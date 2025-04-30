#pragma once
#include "gtest/gtest.h"
#include "../console/console.h"
#include <Windows.h>
#include <iostream>
#include <memory>
#include "../UserManager/UserManager.h"
#include <string>
#include "../Setting/Setting.h"
#include "../Randomized_player/Randomized_Player.h"
using std::cin;
using std::cout;
using std::endl;


class menu
{
private:

	bool setting_loaded=0;
	std::unique_ptr<User> loc_User;
	UserManager& UserMng;
	std::unique_ptr<Setting> setting;

public:
	menu();

	void mini_counter_logo();
	//Flow Control

	void Mini_Counter_Menu();

	//login screen ->Login / Sign up
	void User_Entry();

	void User_Login();

	void User_SignUp();

	//start screen -> 1) Run test,Run test Game, Run Game

	void Start_Screen_Control(int argc, char** argv);


	// class test runner
	
	int Class_Test_Runner(int argc, char** argv);
	// main game runner
	
	void Main_game_Test_runner();
	// ->Run game->start menu -> 1)play ,2)setting ,3)game record , 4)user details ,5)Exit

	void Run_Game_start_Menu();

	//play

	void Run_Game_Play();

	//setting

	void Run_Game_Setting();

	//game record

	void Run_Game_Record();

	//user details

	void Run_Game_Details();





};

