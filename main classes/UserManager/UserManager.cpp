#include "UserManager.h"
#include <regex>

std::unique_ptr<UserManager> UserManager::instance = nullptr;

UserManager::UserManager() 
    : main_filename("data/users.json")
    , test_filename("data/test_users.json")
    , is_test_mode(false)
{
    loadUserFromJson();
}

void UserManager::reset_instance() {
    instance.reset();
}

void UserManager::set_test_mode(bool is_test) {
    if (!instance) {
        instance.reset(new UserManager);
    }
    instance->is_test_mode = is_test;
    instance->user_list.clear();
    instance->loadUserFromJson();
}

User UserManager::from_json(const json& j)
{
    std::vector<Gameround> tmp;
    try {
        if(j.contains("game")) {
            for (const auto& r : j.at("game"))
                tmp.push_back(Gameround::from_json(r));
        }

        return User(
            j.at("Username").get<string>(),
            j.at("nickname").get<string>(),
            j.at("password").get<string>(),
            j.value("wincount", 0),
            j.value("losecount", 0),
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
    string current_file = get_current_filename();

    if (!(fs::exists("data") && fs::is_directory("data"))) {
        fs::create_directories("data");
    }
    
    if (!fs::exists(current_file)) {
        std::ofstream file(current_file);
        json empty_array = json::array();
        file << empty_array.dump(4);
        file.close();
        return;
    }

    try {
        std::ifstream file(current_file);
        if (file.is_open()) {
            if (fs::file_size(current_file) == 0) {
                file.close();
                std::ofstream ofile(current_file);
                json empty_array = json::array();
                ofile << empty_array.dump(4);
                ofile.close();
                return;
            }

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
        user_list.clear();
    }
}

void UserManager::saveUserIntoJson()
{
    if (!(fs::exists("data") && fs::is_directory("data"))) {
        fs::create_directories("data");
    }

    string current_file = get_current_filename();

    try {
        json j_list = json::array();
        for (const auto& user : user_list) {
            j_list.push_back(user.to_json());
        }

        std::ofstream file(current_file);
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

    string hashed_password = User::Hash_SHA_password(simple_Password);
    
    for (const auto& user : user_list) {
        if (user.get_username() == UserName &&
            user.get_hashed_password() == hashed_password)
        {
            User_holder = std::make_unique<User>(user);
            return true;
        }
    }
    
    User_holder = nullptr;
    return false;
}

void UserManager::update_game_record(Gameround& gr, string user_name)
{
    for (auto& user : user_list) {
        if (user.get_username() == user_name) {
            user.add_gameRecord(gr);
            if (gr.won)
                user.player_win();
            else
                user.player_lose();
            saveUserIntoJson();
            break;
        }
    }
}

void UserManager::Reload_User(std::unique_ptr<User>& Userptr)
{
    if (!Userptr) return;
    
    for (const auto& user : user_list) {
        if (user.get_username() == Userptr->get_username() &&
            user.get_hashed_password() == Userptr->get_hashed_password())
        {
            Userptr = std::make_unique<User>(user);
            break;
        }
    }
}

