#include "UserManager.h"
#include <regex>

std::unique_ptr<UserManager> UserManager::instance = nullptr;

UserManager::UserManager() :filename("data/users.json")
{
    loadUserFromJson();
}

User UserManager::from_json(const json& j)
{
    std::vector<Gameround> tmp;
    try {
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
    catch (const json::exception& e) {
        std::vector<Gameround> empty_records;
        return User("", "", "", 0, 0, empty_records);
    }
}

UserManager& UserManager::get_instance()
{
    if (!instance)
        instance.reset(new UserManager);
    return *instance;
}

void UserManager::loadUserFromJson()
{
    user_list.clear();

    if (!(fs::exists("data") && fs::is_directory("data")))
        fs::create_directories("data");
    
    if (fs::exists(filename)) {
        try {
            std::ifstream file(filename);
            if (file.is_open() && fs::file_size(filename) != 0) {
                json j_user;
                file >> j_user;
                if(j_user.is_array()) {
                    for (const auto& j_u : j_user) {
                        User user = from_json(j_u);
                        if(!user.get_username().empty()) {
                            user_list.push_back(user);
                        }
                    }
                }
                file.close();
            }
        }
        catch(const std::exception&) {
            // در صورت خطا در خواندن فایل، لیست خالی را حفظ می‌کنیم
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

void UserManager::Reload_User(std::unique_ptr<User>& Userptr)
{
    for (auto& r : user_list) {
        if (r.get_username() == Userptr->get_username() &&
            r.get_hashed_password() == Userptr->get_hashed_password())
        {
            Userptr.reset(new User(r));
        }
    }
}

void UserManager::saveUserIntoJson()
{
    if (!(fs::exists("data") && fs::is_directory("data")))
        fs::create_directories("data");

    try {
        json j_list = json::array();
        for (const auto& user : user_list) {
            j_list.push_back(user.to_json());
        }

        std::ofstream file(filename);
        if (file.is_open()) {
            file << j_list.dump(4);
            file.close();
        }
    }
    catch(const std::exception&) {
        // در صورت خطا در ذخیره‌سازی، عملیات را ادامه می‌دهیم
    }
}

bool UserManager::validate_username(const string& username) {
    if(username.empty() || username.length() > 100) return false;
    
    // فقط حروف، اعداد و آندرلاین مجاز هستند
    std::regex pattern("^[a-zA-Z0-9_]+$");
    return std::regex_match(username, pattern);
}

bool UserManager::User_register(User& newUser)
{
    // اعتبارسنجی نام کاربری
    if (!validate_username(newUser.get_username())) {
        return false;
    }
    
    // بررسی تکراری نبودن نام کاربری
    for (const auto& user : user_list) {
        if (user.get_username() == newUser.get_username()) {
            return false;
        }
    }
    
    user_list.push_back(newUser);
    saveUserIntoJson();
    return true;
}

bool UserManager::user_Login(string UserName, string simple_Password, std::unique_ptr<User>& User_holder)
{
    if (!validate_username(UserName)) {
        return false;
    }

    for (const auto& user : user_list) {
        if (user.get_username() == UserName &&
            user.get_hashed_password() == User::Hash_SHA_password(simple_Password))
        {
            User_holder = std::make_unique<User>(user);
            return true;
        }
    }
    return false;
}

