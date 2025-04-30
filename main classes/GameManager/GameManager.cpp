#include "GameManager.h"


std::unique_ptr<GameManager> GameManager::instance = nullptr;

GameManager& GameManager::get_instance(std::vector<string> CT, std::vector<string> Terrorist, std::string MapName)
{
	if (!instance)
		instance.reset(new GameManager(CT, Terrorist, MapName));

	return *instance;
}

GameManager::GameManager(std::vector<string>CT, std::vector<string>Terrorist, std::string MapName)
	:Map_name(MapName),CT_player(CT),Terrorist_player(Terrorist)
{
	;
}
