#include "menu.h"

menu::menu() : UserMng(UserManager::get_instance())
{
	;
}

void menu::mini_counter_logo()
{
	std::stringstream logo;

	std::string text = " mini counter 1.7 ";
	int width = text.size() + 2;


	logo << "+" << std::string(width, '-') << "+" << std::endl;

	logo << "|" << text << "  |" << std::endl;


	logo << "+" << std::string(width, '-') << "+" << std::endl;

	logo << "\n";
	Console::printColored(logo.str(), Console::Color::YELLOW);
}

void menu::Mini_Counter_Menu()
{

	User_Entry();

	if (this->loc_User) {
		Run_Game_start_Menu();
	}
}

//User Login

void menu::User_Entry()
{


	int User_choise;
	bool User_Chois_valid;

	do {
		system("cls");

		mini_counter_logo();
		Console::printColored("1) Login \n2) sign up\n3) Exit\n\n->", Console::Color::BRIGHT_YELLOW);
		do {
			User_Chois_valid = true;

			while (!(cin >> User_choise)) { 
				Console::ClearBuffer();
				Console::printColored("WRONGE INPUT\n", Console::Color::BRIGHT_RED);
				Sleep(300);
				Console::ClearLine();
				Console::ClearLine();
				Console::ClearLine();
				Console::printColored("\n-> ", Console::Color::BRIGHT_YELLOW);
			}

			switch (User_choise)
			{
			case(1):
				User_Login();
				if (loc_User) {
					Run_Game_start_Menu();
					return;
				}
				break;
			case(2):
				User_SignUp();
				break;
			case(3):
				system("cls");
				mini_counter_logo();
				Console::printColored("---{ GOOD BYE }---", Console::Color::BRIGHT_YELLOW);
				return;
			default:
				Console::ClearBuffer();
				Console::printColored("WRONGE INPUT\n", Console::Color::BRIGHT_RED);
				Sleep(300);
				Console::ClearLine();
				Console::ClearLine();
				Console::ClearLine();
				Console::printColored("\n-> ", Console::Color::BRIGHT_YELLOW); 
				break;
			}

		} while (!User_Chois_valid);

	} while (User_choise !=3);
}

void menu::User_Login()
{
	system("cls");
	mini_counter_logo();
	UserMng.loadUserFromJson();
	

	Console::printColored("Enter your username :", Console::Color::CYAN);
	string username,pass;
	cin >> username;
	Console::printColored("Enter your Password :", Console::Color::CYAN);
	cin >> pass;

	if (UserMng.user_Login(username, pass, loc_User)) {
		system("cls");
		mini_counter_logo();
		Console::printColored("---{ Welcome }---", Console::Color::BRIGHT_GREEN);

		Sleep(500);
		UserMng.saveUserIntoJson();
	}
	else
	{
		system("cls");
		mini_counter_logo();
		Console::printColored("---{ Login faild }---", Console::Color::RED);

		Sleep(500);
		UserMng.saveUserIntoJson();

	}
}

void menu::User_SignUp()
{
	system("cls");
	mini_counter_logo();
	UserMng.loadUserFromJson();

	string username, nicname, pass1, pass2;
	Console::printColored("Enter username :", Console::Color::CYAN);

	cin >> username;
	
	Console::printColored("\nEnter nickname :", Console::Color::CYAN);

	cin >> nicname;

	Console::printColored("\nEnter a Password :", Console::Color::CYAN);
	
	cin >> pass1;
	
	Console::printColored("\nEnter again a Password :", Console::Color::CYAN);
	
	cin >> pass2;
	
	if (pass1 != pass2) {
		Console::printColored("\nThe entered password does not match its repetition", Console::Color::BRIGHT_RED);
		Sleep(700);

	}
	User tmp(username, nicname, pass1);

	if (UserMng.User_register(tmp)) {
		Console::printColored("\nUser added successfully", Console::Color::GREEN);
		Sleep(300);
		UserMng.saveUserIntoJson();


	}
	else {
		Console::printColored("\nUser was not added successfully.", Console::Color::BRIGHT_RED);
		Sleep(300);
	}
}

void menu::Start_Screen_Control(int argc, char** argv)
{
	int mainChoice;

	do {
		system("cls");
		mini_counter_logo();
		Console::printColored("1) TEST GAME CLASS \n", Console::Color::BRIGHT_MAGENTA);
		Console::printColored("2) TEST MAIN GAME \n", Console::Color::BRIGHT_MAGENTA);
		Console::printColored("3) MAIN GAME \n", Console::Color::BRIGHT_MAGENTA);
		Console::printColored("4) EXIT \n", Console::Color::BRIGHT_MAGENTA);

		Console::printColored("\n-> ", Console::Color::BRIGHT_CYAN);



		while (!(cin >> mainChoice)) {
			Console::ClearBuffer();
			Console::printColored("WRONGE INPUT\n", Console::Color::BRIGHT_RED);
			Sleep(300);
			Console::ClearLine();
			Console::ClearLine();
			Console::ClearLine();
			Console::printColored("\n-> ", Console::Color::BRIGHT_CYAN);
		}

		switch (mainChoice)
		{
		case(1):
			Class_Test_Runner(argc, argv);
			return;
			break;
		case(2):
			Main_game_Test_runner();
			return;
			break;
		case(3):
			User_Entry();
			return;
			break;
		case(4):
			system("cls");
			mini_counter_logo();
			Console::printColored("---{ GOOD BYE }---", Console::Color::BRIGHT_YELLOW);
			return;

		default:
			Console::printColored("\nWRONGE CHOICE\n", Console::Color::BRIGHT_RED);
			break;
		}


	} while (mainChoice != 4);

	return;
}

int menu::Class_Test_Runner(int argc, char** argv)
{
	system("cls");

	mini_counter_logo();  
	::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

void menu::Main_game_Test_runner()
{
	;
}


//Run Game
void menu::Run_Game_start_Menu()
{
	int StartChoice;

	do {
		system("cls"); 
		mini_counter_logo();
		Console::printColored("1) PLAY \n", Console::Color::MAGENTA);
		if (!setting_loaded)
			Console::printColored("2) SETTING \n", Console::Color::BRIGHT_YELLOW);
		else
			Console::printColored("2) SETTING \n", Console::Color::MAGENTA);

		Console::printColored("3) GAME HISTORY \n", Console::Color::MAGENTA);
		Console::printColored("4) USER DETAILS \n", Console::Color::MAGENTA);
		Console::printColored("5) EXIT \n", Console::Color::MAGENTA);

		Console::printColored("\n-> ", Console::Color::BRIGHT_CYAN);



		while (!(cin >> StartChoice)) {
			Console::ClearBuffer();
			Console::printColored("WRONGE INPUT\n", Console::Color::BRIGHT_RED);
			Sleep(300);
			Console::ClearLine();
			Console::ClearLine();
			Console::ClearLine();
			Console::printColored("\n-> ", Console::Color::BRIGHT_CYAN);
		}

		switch (StartChoice)
		{
		case(1):
			Run_Game_Play();
			break;
		case(2):
			Run_Game_Setting();
			break;
		case(3):
			Run_Game_Record();
			break;
		case(4):
			Run_Game_Details();
			break;
		case(5):
			system("cls");
			mini_counter_logo();
			Console::printColored("---{ GOOD BYE }---", Console::Color::BRIGHT_YELLOW);
			return;

		default:
			Console::printColored("\nWRONGE CHOICE\n", Console::Color::BRIGHT_RED);
			break;
		}


	} while (StartChoice != 5);
	
	return;

}

void menu::Run_Game_Play()
{
	if (setting_loaded) {
		system("cls");
		mini_counter_logo();
		cout << "\n"; 

		GameManager::Run_Game();

		auto& tmp = GameManager::get_instance(std::vector<std::string>(), std::vector<std::string>(), "", 0).get_game_result();

		auto& winner = GameManager::get_instance(std::vector<std::string>(), std::vector<std::string>(), "", 0).get_winner();
		UserMng.update_game_record(tmp, loc_User->get_username());
		UserMng.saveUserIntoJson();
		Console::printColored("\n==={ ", Console::Color::BRIGHT_MAGENTA);
		Console::printColored(winner, Console::Color::BRIGHT_MAGENTA);
		Console::printColored(" WIN }===\n", Console::Color::BRIGHT_MAGENTA);

		Console::waiter();
		setting_loaded = false;
	}
}

void menu::Run_Game_Setting()
{
	system("cls");
	mini_counter_logo();
	// setting creat

	this->setting.reset(new Setting());

	// select side;

	
	Console::printColored("Select your side (CT : 1) , (Terrorist : 0) :\n-> ", Console::Color::BRIGHT_BLUE);
	int side;
	bool side_setted;
	do {
		side_setted = true;
		while (!(cin >> side)) {
			Console::ClearBuffer();
			Console::printColored("WRONGE INPUT\n", Console::Color::BRIGHT_RED);
			Sleep(400);
			Console::ClearLine();
			Console::ClearLine(); 
			Console::ClearLine();
			Console::printColored("Select your side (CT : 1) , (Terrorist : 0) :\n-> ", Console::Color::BRIGHT_BLUE);

		}

		switch (side)
		{
		case(0):
			setting->set_player_side(false);
			Console::printColored("Your side became a Terrorist.\n", Console::Color::BRIGHT_GREEN);
			
			break;
		case(1):
			setting->set_player_side(true);
			Console::printColored("Your side became a CT.\n", Console::Color::BRIGHT_GREEN);

			break;
		default:
			side_setted = false;
			Console::printColored("WRONGE CHOICE\n", Console::Color::BRIGHT_RED);
			Sleep(400);
			Console::ClearLine();
			Console::ClearLine();
			Console::ClearLine();
			Console::printColored("Select your side (CT : 1) , (Terrorist : 0) :\n-> ", Console::Color::BRIGHT_BLUE);

			break;
		} 
	} while (!side_setted);
	
	// select map;
	
	Console::printColored("\n==={ Select Game Map }===\n", Console::Color::BRIGHT_MAGENTA);
	int cnt = 1;
	for (auto map : setting->get_map_list()) {
		std::stringstream ss;
		ss << cnt++ <<") Map name :" << map->get_MapName() << " | Map Creator :" << map->get_MapCreator() << " | " << ((map->is_dayTime()) ? ("day\n") : ("night\n"));
		Console::printColored(ss.str(), Console::Color::YELLOW);
	}
	int map_index;
	bool map_setted;
	Console::printColored("\n-> ", Console::Color::BRIGHT_MAGENTA);
	do {
		map_setted = true;
		while (!(cin >> map_index)) {
			Console::ClearBuffer();
			Console::printColored("WRONGE INPUT\n", Console::Color::BRIGHT_RED);
			Sleep(400);
			Console::ClearLine();
			Console::ClearLine();
			Console::ClearLine();
			Console::printColored("\n-> ", Console::Color::BRIGHT_MAGENTA);

		}

		if (map_index < 1 || map_index > setting->get_map_list().size()) {
			map_setted = false;
			Console::printColored("WRONGE CHOICE\n", Console::Color::BRIGHT_RED);
			Sleep(400);
			Console::ClearLine();
			Console::ClearLine();
			Console::ClearLine();
			Console::printColored("\n-> ", Console::Color::BRIGHT_YELLOW);

		}
		else {
			setting->set_selected_map(map_index);
			Console::printColored("Map setted\n", Console::Color::BRIGHT_GREEN);

		}

	} while (!map_setted);

	//get ct & terror number

	bool both_setted = true;
	int CT_number, terror_number;
	bool CT_setted, Terror_setted;

	do {
		both_setted = true;


		Console::printColored("\nEnter CT Team member number : ", Console::Color::BRIGHT_BLUE);
		do {
			CT_setted = true;
			while (!(cin >> CT_number)) {
				Console::ClearBuffer();
				Console::printColored("WRONGE INPUT\n", Console::Color::BRIGHT_RED);
				Sleep(400);
				Console::ClearLine();
				Console::ClearLine();
				Console::ClearLine();
				Console::printColored("\nEnter CT Team member number : ", Console::Color::BRIGHT_BLUE);

			}
			if (CT_number < 1 || CT_number >100) {
				CT_setted = false;
				Console::printColored("WRONGE NUMBER\n", Console::Color::BRIGHT_RED);
				Sleep(400);
				Console::ClearLine();
				Console::ClearLine();
				Console::ClearLine();
				Console::printColored("\nEnter CT Team member number : ", Console::Color::BRIGHT_BLUE);
				 
			}
			else {
				setting->set_CT_number(CT_number);
				Console::printColored("SETTED\n", Console::Color::BRIGHT_GREEN);
			}
		} while (!CT_setted);

		Console::printColored("\nEnter Terrorist Team member number : ", Console::Color::YELLOW);
		do {
			Terror_setted = true;
			while (!(cin >> terror_number)) {
				Console::ClearBuffer();
				Console::printColored("WRONGE INPUT\n", Console::Color::BRIGHT_RED);
				Sleep(400);
				Console::ClearLine();
				Console::ClearLine();
				Console::ClearLine();
				Console::printColored("\nEnter Terrorist Team member number : ", Console::Color::YELLOW);

			}
			if (terror_number < 1 || terror_number >100) {
				Terror_setted = false;
				Console::printColored("WRONGE NUMBER\n", Console::Color::BRIGHT_RED);
				Sleep(400);
				Console::ClearLine();
				Console::ClearLine();
				Console::ClearLine();
				Console::printColored("\nEnter Terrorist Team member number : ", Console::Color::YELLOW);

			}
			else {
				setting->set_terror_number(terror_number);
				Console::printColored("SETTED\n", Console::Color::BRIGHT_GREEN);
			}
		} while (!Terror_setted);

		double tmp = (CT_number + 0.0) / terror_number;
		if (!(tmp >= 0.95 && tmp <= 1.05)) {
			both_setted = false;
			Console::printColored("Teams member number not balance, Enter again\n", Console::Color::BRIGHT_RED);
			Sleep(500);
			Console::ClearLine();
			Console::ClearLine();
			Console::ClearLine();
			Console::ClearLine();
			Console::ClearLine();
			Console::ClearLine();
			Console::ClearLine();

		}
	} while (!both_setted);

	//get player monye
	int monye_mode;
	bool monye_mode_setted;

	Console::printColored("Set monye Randomliy { 0)random , 1)manual }: ", Console::Color::BRIGHT_MAGENTA);

	do {
		monye_mode_setted = true;
		while (!(cin >> monye_mode)) {
			Console::ClearBuffer();
			Console::printColored("WRONGE INPUT\n", Console::Color::BRIGHT_RED);
			Sleep(400);
			Console::ClearLine();
			Console::ClearLine();
			Console::ClearLine();
			Console::printColored("Set monye Randomliy { 0)random , 1)manual }: ", Console::Color::BRIGHT_MAGENTA);



		}

		switch (monye_mode)
		{
		case(0):
		case(1):
			Console::printColored("MODE SETTED\n", Console::Color::BRIGHT_GREEN);

			break;
		default:
			monye_mode_setted = false;
			Console::printColored("WRONGE CHOICE\n", Console::Color::BRIGHT_RED);
			Sleep(400);
			Console::ClearLine();
			Console::ClearLine();
			Console::ClearLine();
			Console::printColored("Set monye Randomliy { 0)random , 1)manual }: ", Console::Color::BRIGHT_MAGENTA);


			break;
		}
	} while (!monye_mode_setted);






	std::vector<int>ct_monye;
	std::vector<int>terror_monye;

	if (monye_mode) {
		if (setting->get_side_is_CT()) {
			CT_number--;
			setting->set_CT_number(CT_number);
		}
		else
		{
			terror_number--;
			setting->set_terror_number(terror_number);
		}
		Console::printColored("\nEnter Your monye : ", Console::Color::BRIGHT_MAGENTA);

		bool player_monye_setted;
		int player_monye;
		do {
			player_monye_setted = true;
			while (!(cin >> player_monye)) {
				Console::ClearBuffer();
				Console::printColored("WRONGE INPUT\n", Console::Color::BRIGHT_RED);
				Sleep(400);
				Console::ClearLine();
				Console::ClearLine();
				Console::ClearLine();

				Console::printColored("\nEnter Your monye : ", Console::Color::BRIGHT_MAGENTA);


			}
			if (player_monye <= 0) {
				player_monye_setted = false;
				Console::printColored("WRONGE NUMBER\n", Console::Color::BRIGHT_RED);
				Sleep(400);
				Console::ClearLine();
				Console::ClearLine();
				Console::ClearLine();

				Console::printColored("\nEnter Your monye : ", Console::Color::BRIGHT_MAGENTA);


			}
			else {
				if (setting->get_side_is_CT()) {
					ct_monye.push_back(player_monye);
				}
				else {
					terror_monye.push_back(player_monye);
				}
			}
		} while (!player_monye_setted);

		//get CT monye


		for (int i = 1; i <= CT_number; i++) {
			std::stringstream tmp_q;

			tmp_q << "\nEnter CT_player " << i << " monye : ";

			Console::printColored(tmp_q.str(), Console::Color::BRIGHT_BLUE);

			bool tmp_setted;
			int tmp_monye;
			do {
				tmp_setted = true;
				while (!(cin >> tmp_monye)) {
					Console::ClearBuffer();
					Console::printColored("WRONGE INPUT\n", Console::Color::BRIGHT_RED);
					Sleep(400);
					Console::ClearLine();
					Console::ClearLine();
					Console::ClearLine();
					Console::printColored(tmp_q.str(), Console::Color::BRIGHT_BLUE);


				}
				if (tmp_monye <= 0) {
					tmp_setted = false;
					Console::printColored("WRONGE NUMBER\n", Console::Color::BRIGHT_RED);
					Sleep(400);
					Console::ClearLine();
					Console::ClearLine();
					Console::ClearLine();
					Console::printColored(tmp_q.str(), Console::Color::BRIGHT_BLUE);


				}
				else {

					ct_monye.push_back(tmp_monye);
				}
			} while (!tmp_setted);

		}


		//get terrorist monye

		for (int i = 1; i <= terror_number; i++) {
			std::stringstream tmp_q;

			tmp_q << "\nEnter Terrorist_player " << i << " monye : ";

			Console::printColored(tmp_q.str(), Console::Color::YELLOW);

			bool tmp_setted;
			int tmp_monye;
			do {
				tmp_setted = true;
				while (!(cin >> tmp_monye)) {
					Console::ClearBuffer();
					Console::printColored("WRONGE INPUT\n", Console::Color::BRIGHT_RED); 
					Sleep(400);
					Console::ClearLine();
					Console::ClearLine();
					Console::ClearLine();
					Console::printColored(tmp_q.str(), Console::Color::YELLOW);


				}
				if (tmp_monye <= 0) {
					tmp_setted = false;
					Console::printColored("WRONGE NUMBER\n", Console::Color::BRIGHT_RED);
					Sleep(400);
					Console::ClearLine();
					Console::ClearLine();
					Console::ClearLine();
					Console::printColored(tmp_q.str(), Console::Color::YELLOW);


				}
				else {

					terror_monye.push_back(tmp_monye);
				}
			} while (!tmp_setted);
		}
	}
	else {
		for (int i = 0; i < CT_number;i++) {
			ct_monye.push_back(mrand::Random_number(120, 500));
		}
		for (int i = 0; i < terror_number; i++) {
			terror_monye.push_back(mrand::Random_number(120, 500));
		}
	} 
	// build
	int player_create = true;
	for (int monye : ct_monye) {
		if (setting->get_side_is_CT() && player_create) {
			setting->push_CT_back(Randomized::get_random_CT(loc_User->get_username(), monye, 0));
			player_create = false;
		}
		else {
			setting->push_CT_back(Randomized::get_random_CT(monye, 1));
		}
	}
	int bomb_dist = mrand::Random_number(0, terror_number - 1);

	for (int i = 0; i < terror_number; i++) {
		bool bomb = false;
		if (bomb_dist == i) {
			bomb = true;
		}
		if (!setting->get_side_is_CT() && player_create) {
			setting->push_Terror_back(Randomized::get_random_Terrorist(loc_User->get_username(), terror_monye[i], 0, bomb)); 
			player_create = false;
		}
		else
			setting->push_Terror_back(Randomized::get_random_Terrorist(terror_monye[i], 1, bomb));
	}

	GameManager::Reset_instance(setting->get_CT_list(), setting->get_terror_list(), setting->get_selected_map().lock()->get_MapName(), setting->get_side_is_CT());
	
	//end

	Console::printColored("\n==={ Setting Setted }===", Console::Color::BRIGHT_GREEN);
	Sleep(1200);
	setting_loaded = true;
 }

void menu::Run_Game_Record()
{
	UserMng.loadUserFromJson();
	UserMng.Reload_User(loc_User);
	system("cls");
	mini_counter_logo();
	Console::printColored("------Game Record : \n", Console::Color::YELLOW);
	for (auto& round : loc_User->get_gameRecord()) {
		if (round.won) {
			Console::printColored(round.to_string(), Console::Color::GREEN);
		}
		else
			Console::printColored(round.to_string(), Console::Color::RED);

		cout << "\n";
	}
	Console::waiter();
	return ;
}

void menu::Run_Game_Details()
{
		UserMng.loadUserFromJson();
		UserMng.Reload_User(loc_User);
		system("cls");
		mini_counter_logo();
		Console::printColored("User Name :", Console::Color::BRIGHT_BLUE);
		Console::printColored(loc_User->get_username(), Console::Color::BRIGHT_BLUE);
		Console::printColored("\nNick name :", Console::Color::BRIGHT_BLUE);
		Console::printColored(loc_User->get_nickname(), Console::Color::BRIGHT_BLUE);
		Console::printColored("\nWin count :", Console::Color::GREEN);
		Console::printColored(std::to_string(loc_User->get_winCount()), Console::Color::GREEN);
		Console::printColored("\nLose count :", Console::Color::RED);
		Console::printColored(std::to_string(loc_User->get_loseCount()), Console::Color::RED);
		cout << "\n";
		Console::waiter();
		return;
}
