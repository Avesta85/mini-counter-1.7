#pragma once
#include "console.h"
#include <Windows.h>
#include <iostream>
#include <memory>
#include "UserManager.h"
#include <string>
#include "Setting.h"

using std::cin;
using std::cout;
using std::endl;


class menu
{
private:
	enum {
		defualt = -1,
		Playe = 1,
		Setting_m = 2,
		game_history = 3,
		user_menu = 4,
		exit = 5,
		start
	};

	bool setting_loaded=0;
	std::unique_ptr<User> loc_User;
	UserManager& UserMng;
	std::unique_ptr<Setting> setting;

public:
	menu();

	//menu control
	
	void menu_handeler();

	int get_event(int);

	//menu
	int start_menu();
	int play_menu();
	int setting_menu();
	int gameHistory_menu();
	int User_menu();
	void Safe_Exit();

	//login/sign up menu
	void login_handel();
	
	bool login_menu();
	
	bool signUp_menu();
};

