#include "UserManager.h"

std::unique_ptr<UserManager> UserManager::instance = nullptr;

UserManager::UserManager() :filename("data/User_database.Json")
{
    ;
}

User UserManager::from_json(const json& j)
{
    std::vector<Gameround> tmp;
    for (const auto& r : j.at("game"))
        tmp.push_back(Gameround::from_json(r));

    return User(
        j.at("Username").get<string>(),
        j.at("nickname").get<string>(),
        j.at("password").get<string>(),
        j.at("wincount").get<int>(),
        j.at("losecount").get<int>(),
        tmp
    );
}

UserManager& UserManager::get_instance()
{
    if (!instance)
        instance.reset(new UserManager);

    return *instance;
}
void UserManager::loadUserFromJson()
{

    std::ifstream file(filename);
    
    //dir check
    if (!(fs::exists("data") && fs::is_directory("data")))
        fs::create_directories("data");
    
    //load
    if (fs::exists(filename)) {

        std::ifstream file(filename);

        if (file.is_open() && fs::file_size(filename) != 0)
        {
            json j_user;
            
            file >> j_user;

            for (auto& j_u : j_user) {
                user_list.push_back(from_json(j_u));
            }
            file.close();
        }



    }

}

void UserManager::update_game_record(Gameround& gr, string user_name)
{
    for (auto& r : user_list) {
        if (r.get_username() == user_name) {
            r.add_gameRecord(gr);
            if (gr.won)
                r.player_win();
            else
                r.player_lose();
        }
    }
}


void UserManager::saveUserIntoJson()
{
    json j_list = json::array();

    for (auto& U : user_list)
        j_list.push_back(U.to_json());

    //dir check
    if (!(fs::exists("data") && fs::is_directory("data")))
        fs::create_directories("data");

  
    //load
    
    std::ofstream file(filename);

    if (fs::exists(filename)) {
  
        if (file.is_open())
        {

            file << j_list.dump(4);
            file.close();

        }



    }

}

bool UserManager::User_register(User& newUser)
{
    for (auto r : user_list) {
        if (r.get_username() == newUser.get_username()) {
            return false;
        }
    }
    user_list.push_back(newUser);
    return true;
}

bool UserManager::user_Login(string UserName, string simple_Password, std::unique_ptr<User>& User_holder)
{
    for (auto& r : user_list) {
        if (r.get_username() == UserName &&
            r.get_hashed_password() == User::Hash_SHA_password(simple_Password)
            )
        {
            User_holder.reset(new User(r));
            return true;
        }
    }
    return false;
}

