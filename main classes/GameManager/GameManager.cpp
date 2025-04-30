#include "GameManager.h"
#include <Windows.h>

std::unique_ptr<GameManager> GameManager::instance = nullptr;

GameManager& GameManager::get_instance(std::vector<string> CT, std::vector<string> Terrorist, std::string MapName, bool is_ct)
{
	if (!instance)
		instance.reset(new GameManager(CT, Terrorist, MapName,is_ct));

	return *instance;
}

GameManager& GameManager::Reset_instance(std::vector<string> CT, std::vector<string> Terrorist, std::string MapName, bool is_ct)
{
	instance.reset(new GameManager(CT, Terrorist, MapName,is_ct)); 

	return *instance;
}

void GameManager::Run_Game()
{
	int CT_Pointer = 0;
	int Terror_Pointer = 0;
	bool ct_first_kill{};
	bool first_match = true; 
	while (CT_still_on() && Terrorist_still_on()) {  
		Sleep(500);
		bool tmp_ct = CT::get_from_map(instance->CT_player[CT_Pointer % instance->CT_player.size()])->is_Alive();
		bool tmp_terror =Terrorist::get_from_map(instance->Terrorist_player[Terror_Pointer % instance->Terrorist_player.size()])->is_Alive();

		if (tmp_ct && tmp_terror) {
			int result = PlayerVsPlayer(instance->CT_player[CT_Pointer % instance->CT_player.size()], instance->Terrorist_player[Terror_Pointer % instance->Terrorist_player.size()]);

			if (result == 0) {
				if (first_match) {
					ct_first_kill = true;
					first_match = false;
				}
				Terror_Pointer++;
			}
			else if (result == 1) {
				if (first_match) {
					ct_first_kill = false;
					first_match = false;
				}
				CT_Pointer++;
			}
			else {
				CT_Pointer++;
				Terror_Pointer++;
			}
		}
		else if (tmp_ct) {
			Terror_Pointer++;
		}
		else if (tmp_terror) {
			CT_Pointer++;
		}
		else {
			CT_Pointer++;
			Terror_Pointer++;
		}
		
	}
	Gameround tmp;

	tmp.is_CT = instance->player_is_ct;
	if (CT_still_on()) {
		instance->winner = "CT";
		tmp.won = instance->player_is_ct;
	}
	else if (Terrorist_still_on()) {
		instance->winner = "Terrorist";
		tmp.won = !instance->player_is_ct;
	}
	else {
		if (ct_first_kill) {
			instance->winner = "CT";

			tmp.won = instance->player_is_ct;
		}
		else {
			instance->winner = "Terrorist";
			tmp.won = !instance->player_is_ct;
		}
	}
	
	instance->match_resualt = tmp;
}

Gameround& GameManager::get_game_result()
{
	return instance->match_resualt;
}

std::string& GameManager::get_winner()
{
	return instance->winner;
}

bool GameManager::CT_still_on()
{
	for (auto& id : instance->CT_player) {
		if (CT::get_from_map(id)->is_Alive())
			return true;
	}
	return false;
}

bool GameManager::Terrorist_still_on()
{
	for (auto& id : instance->Terrorist_player) {
		if (Terrorist::get_from_map(id)->is_Alive())
			return true;
	}
	return false;
}


int GameManager::PlayerVsPlayer(std::string& ct_player, std::string& terror_player) 
{
	auto&& player1 = CT::get_from_map(ct_player);
	auto&& player2 = Terrorist::get_from_map(terror_player);

	int power_p1 = player1->get_total_Gun_power() + player1->get_monye();
	int power_p2 = player2->get_total_Gun_power() + player2->get_monye();


	if (power_p1/10 > power_p2/10) {
		
		int diff = power_p1 - power_p2;

		if (player1->get_armor() + player1->get_health() - diff / 3 >= 0) {

			int new_player2_armor = player2->get_armor() - diff;
			int new_player2_health = player2->get_health() + (new_player2_armor < 0) ? (new_player2_armor) : (0);


			int new_player1_armor = player1->get_armor() - diff / 3;
			int new_player1_health = player1->get_health() + (new_player1_armor < 0) ? (new_player1_armor) : (0);

			player1->set_armor(((new_player1_armor > 0) ? new_player1_armor : 0));
			player1->set_health(((new_player1_health > 0) ? new_player1_health : 100));
			 
			player2->set_armor(new_player2_armor);
			player2->set_health(new_player2_health);

			if (player2->is_Alive()) {
				Console::Player_To_Player(ct_player, terror_player, 1, 0, 0, 0);
			}
			else {
				Console::Player_To_Player(ct_player, terror_player, 1, 0, 1, 0);
			}
			return 0;
		}
		else {
			int damage = power_p2 / 2;
			int new_player1_armor = player1->get_armor() - damage;
			int new_player1_health = player1->get_health() + ((new_player1_armor < 0) ? (new_player1_armor) : (0));

			player1->set_armor(new_player1_armor);
			player1->set_health(new_player1_health);

			int new_player2_armor = player2->get_armor() - damage;
			int new_player2_health = player2->get_health() + (new_player2_armor < 0) ? (new_player2_armor) : (0);

			player2->set_armor(new_player2_armor);
			player2->set_health(new_player2_health);

			Console::Player_To_Player(ct_player, terror_player, 1, 0, 0, 1);
			return 2;
		}
	}
	else if (power_p1/10 < power_p2/10) {
		int diff = power_p2 - power_p1;
		if (player2->get_armor() + player2->get_health() - diff / 3 >= 0) {

			int new_player1_armor = player1->get_armor() - diff;
			int new_player1_health = player1->get_health() + (new_player1_armor < 0) ? (new_player1_armor) : (0);

			player1->set_armor(new_player1_armor);
			player1->set_health(new_player1_health);


			int new_player2_armor = player2->get_armor() - diff / 3;
			int new_player2_health = player2->get_health() + (new_player2_armor < 0) ? (new_player2_armor) : (0);

			player2->set_armor(((new_player2_armor > 0) ? new_player2_armor : 0));
			player2->set_health(((new_player2_health > 0) ? new_player2_health : 100));

			if (player1->is_Alive()) {
				Console::Player_To_Player(terror_player, ct_player, 0, 1, 0, 0);
			}
			else {
				Console::Player_To_Player(terror_player, ct_player, 0, 1, 1, 0);
			}
			return 1;
		}
		else {
			int damage = power_p2 / 2;
			int new_player1_armor = player1->get_armor() - damage;
			int new_player1_health = player1->get_health() + ((new_player1_armor < 0) ? (new_player1_armor) : (0));

			player1->set_armor(new_player1_armor);
			player1->set_health(new_player1_health);

			int new_player2_armor = player2->get_armor() - damage;
			int new_player2_health = player2->get_health() + (new_player2_armor < 0) ? (new_player2_armor) : (0);

			player2->set_armor(new_player2_armor);
			player2->set_health(new_player2_health);

			Console::Player_To_Player(ct_player, terror_player, 1, 0, 0, 1);
			return 2;
		}
	}
	else {
		int damage = power_p2 /2;
		int new_player1_armor = player1->get_armor() - damage;
		int new_player1_health = player1->get_health() + ((new_player1_armor < 0) ? (new_player1_armor) : (0));

		player1->set_armor(new_player1_armor);
		player1->set_health(new_player1_health);

		int new_player2_armor = player2->get_armor() - damage;
		int new_player2_health = player2->get_health() + (new_player2_armor < 0) ? (new_player2_armor) : (0);

		player2->set_armor(new_player2_armor);
		player2->set_health(new_player2_health);

		Console::Player_To_Player(ct_player, terror_player, 1, 0, 0, 1);
		return 2;
	}
	
}

GameManager::GameManager(std::vector<string>CT, std::vector<string>Terrorist, std::string MapName, bool is_ct)
	:Map_name(MapName),CT_player(CT),Terrorist_player(Terrorist),player_is_ct(is_ct)
{
	;
}
