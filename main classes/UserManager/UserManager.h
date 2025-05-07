#pragma once
#include <memory>
#include <vector>
#include <string>
#include <nlohmann/json.hpp>
#include <fstream>
#include <filesystem>
#include "../User/User.h"

using string = std::string;
using json = nlohmann::json;
using Uvector = std::vector<User>;
namespace fs = std::filesystem;

class UserManager
{
public:
	static UserManager& get_instance();
	static void reset_instance();
	static void set_test_mode(bool is_test); 

	//load
	void loadUserFromJson();

	//update
	void update_game_record(Gameround& gr, string user_name);
	void Reload_User(std::unique_ptr<User>& Userptr);

	//save
	void saveUserIntoJson();

	//register User
	bool User_register(User& newUser);

	//login
	bool user_Login(string UserName, string simple_Password, std::unique_ptr<User>& User_holder);

private:
	UserManager();
	UserManager(const UserManager&) = delete;
	UserManager& operator=(const UserManager&) = delete;

	// اعتبارسنجی نام کاربری
	bool validate_username(const string& username);

	static std::unique_ptr<UserManager> instance;
	Uvector user_list;
	const string main_filename;
	const string test_filename;
	bool is_test_mode;
	
	string get_current_filename() const {
		return is_test_mode ? test_filename : main_filename;
	}

	User from_json(const json& j);
};