#include "menu.h"

menu::menu() : UserMng(UserManager::get_instance())
{
	;
}

void menu::menu_handeler()
{
	//setup

	
	//login

	login_handel();

	//game menu

	while (get_event(start_menu()) != exit) {
		Sleep(600);
	}
	Safe_Exit();
}

int menu::get_event(int cis)
{

	switch (cis)
	{

	case(Playe):
		break;
	case(Setting_m):
		break;
	case(game_history):
		gameHistory_menu();
		return game_history;
		break;
	case(user_menu):
		User_menu();
		return user_menu;
		break;
	case(exit):
		return exit;
	case(start)://in barar gostaresh
	default:
		Console::printColored("\nWRONGE INPUT\n", Console::Color::BRIGHT_RED);
		return defualt;
		break;
	}

}

int menu::start_menu()
{
	system("cls");
	Console::printColored("1) PLAY \n", Console::Color::MAGENTA);
	if (!setting_loaded)
		Console::printColored("2) SETTING \n", Console::Color::BRIGHT_YELLOW);
	else
		Console::printColored("2) SETTING \n", Console::Color::MAGENTA);

	Console::printColored("3) GAME HISTORY \n", Console::Color::MAGENTA);
	Console::printColored("4) USER DETAILS \n", Console::Color::MAGENTA);
	Console::printColored("5) EXIT \n", Console::Color::MAGENTA);

	Console::printColored("\nENTER...\n-> ", Console::Color::BRIGHT_CYAN);
	int cis;
	cin >> cis;

	return cis;

}

int menu::setting_menu()
{
	setting.reset(new Setting());
	system("cls");
	Console::printColored("Select your side (CT : 1) , (Terrorist : 0) :\n-> ", Console::Color::BLUE);

	int tmp;
	cin >> tmp;
	
	setting->set_player_side(tmp);
	Console::printColored("\nSelect Game Map\n", Console::Color::BLUE);
	int cnt = 1;
	for (auto map : setting->get_map_list()) {
		std::stringstream ss;
		ss << cnt++ <<") Map name :" << map->get_MapName() << " | Map Creator :" << map->get_MapCreator() << " | " << ((map->is_dayTime()) ? ("day") : ("night"))<<"\n->";
	}
	int map_index;
	cin >> map_index;

	setting->set_selected_map(map_index);
	int ct_count, terror_count;

	Console::printColored("Enter CT number :",Console::Color::YELLOW);
	cin >> ct_count;
	Console::printColored("Enter CT number :",Console::Color::YELLOW);
	cin >> terror_count;

	setting->set_CT_number(ct_count);
	setting->set_terror_number(terror_count);
	//validation

	
}

int menu::gameHistory_menu()
{
	system("cls");
	Console::printColored("------Game Record : \n", Console::Color::YELLOW);
	for (auto& round : loc_User->get_gameRecord()) {
		if (round.won) {
			Console::printColored(round.to_string(), Console::Color::GREEN);
		}
		else
			Console::printColored(round.to_string(), Console::Color::RED);

	}
	Console::waiter();
	return start;
}

int menu::User_menu()
{
	system("cls");
	Console::printColored("User Name :", Console::Color::BLUE);
	Console::printColored(loc_User->get_username(), Console::Color::BLUE);
	Console::printColored("\nNick name :", Console::Color::BLUE);
	Console::printColored(loc_User->get_nickname(), Console::Color::BLUE);
	Console::printColored("\nWin count :", Console::Color::GREEN);
	Console::printColored(std::to_string(loc_User->get_winCount()), Console::Color::GREEN);
	Console::printColored("\nLose count :", Console::Color::RED);
	Console::printColored(std::to_string(loc_User->get_loseCount()), Console::Color::RED);
	cout << "\n";
	Console::waiter();
	return start;
}

void menu::Safe_Exit()
{
	system("cls");

	Console::printColored("---{ GOOD BYE }---", Console::Color::BRIGHT_YELLOW);

}

void menu::login_handel()
{
	while (1) {
		system("cls");
		Console::printColored("1) Login \n", Console::Color::BRIGHT_YELLOW);
		Console::printColored("2) sign up\n-> ", Console::Color::BRIGHT_YELLOW);

		int tmp;
		cin >> tmp;

		if (tmp == 1 && login_menu()) {
			return;
		}
		else if (tmp == 2 && signUp_menu()) {
			// bararye ezafe kardan chize jadid badan
		}

	}
}

bool menu::login_menu()
{
	system("cls");
	UserMng.loadUserFromJson();
	Console::printColored("Enter your username :", Console::Color::CYAN);
	string username,pass;
	cin >> username;
	Console::printColored("Enter your Password :", Console::Color::CYAN);
	cin >> pass;

	if (UserMng.user_Login(username, pass, loc_User)) {
		system("cls");

		Console::printColored("---{ Welcome }---", Console::Color::BRIGHT_GREEN);

		Sleep(500);
		UserMng.saveUserIntoJson();
		return true;
	}
	else
	{
		system("cls");

		Console::printColored("---{ Login faild }---", Console::Color::RED);

		Sleep(500);
		UserMng.saveUserIntoJson();
		return false;
	}
}

bool menu::signUp_menu()
{

	system("cls");
	
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
		return false;
	}
	User tmp(username, nicname, pass1);

	if (UserMng.User_register(tmp)) {
		Console::printColored("\nUser added successfully", Console::Color::GREEN);
		Sleep(300);
		UserMng.saveUserIntoJson();
		return true;

	}
	else {
		Console::printColored("\nUser was not added successfully.", Console::Color::BRIGHT_RED);
		Sleep(300);
		return false;
	}
}
