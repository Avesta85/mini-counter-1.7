#pragma once
#include <memory>
#include <vector>
#include <string>
#include <nlohmann/json.hpp>
#include <fstream>
#include <filesystem>
#include "User.h"


using string = std::string;
using json = nlohmann::json;
using Uvector = std::vector<User>;
namespace fs = std::filesystem ;

class UserManager
{

public:

	static UserManager& get_instance();

	//load

	void loadUserFromJson();

	//update

	void update_game_record(Gameround& gr,string user_name);

	//save

	void saveUserIntoJson();

	//register User

	bool User_register(User& newUser);

	//login

	bool user_Login(string UserName, string simple_Password,std::unique_ptr<User>& User_holder);

private:

	UserManager();

	UserManager(const UserManager&) = delete;
	UserManager& operator=(const UserManager&) = delete;

	static std::unique_ptr<UserManager> instance;
	Uvector user_list;
	const string filename;

	User from_json(const json& j);
};