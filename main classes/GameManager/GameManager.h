#pragma once
#include <memory>
#include <vector>
#include "CT_Class.h"
#include "TerroristClass.h"
#include "GameMap.h"


class GameManager
{
public:

	static GameManager& get_instance(std::vector<string>CT, std::vector<string> Terrorist, std::string MapName);


private:

	GameManager(std::vector<string>CT, std::vector<string>Terrorist, std::string MapName);

	GameManager(const GameManager&) = delete;
	GameManager& operator=(const GameManager&) = delete;

	
	static std::unique_ptr<GameManager> instance;

	std::vector<string> CT_player;
	std::vector<string> Terrorist_player;

	std::string Map_name;

	std::string winner;

};