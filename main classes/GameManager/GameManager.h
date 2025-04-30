#pragma once
#include <memory>
#include <vector>
#include "../CT_Class/CT_Class.h"
#include "../TerroristClass/TerroristClass.h"
#include "../GameMap/GameMap.h"
#include "../Console/console.h"
#include "../User/User.h"


class GameManager
{
public:

	static GameManager& get_instance(std::vector<string>CT, std::vector<string> Terrorist, std::string MapName, bool is_ct);
	static GameManager& Reset_instance(std::vector<string>CT, std::vector<string> Terrorist, std::string MapName, bool is_ct);

	static void Run_Game();
	
	Gameround& get_game_result();
	std::string& get_winner();

private:
	
	static bool CT_still_on();
	static bool Terrorist_still_on();

	static int PlayerVsPlayer(std::string& ct_player, std::string& terror_player);

	GameManager(std::vector<string>CT, std::vector<string>Terrorist, std::string MapName,bool is_ct);

	GameManager(const GameManager&) = delete;
	GameManager& operator=(const GameManager&) = delete;

	
	static std::unique_ptr<GameManager> instance;

	std::vector<string> CT_player;
	std::vector<string> Terrorist_player;

	std::string Map_name;

	std::string winner;

	bool player_is_ct;

	Gameround match_resualt;
};