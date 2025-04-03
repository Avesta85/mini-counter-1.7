#include "GameMap.h"

GameMap::GameMap(std::string map_name, std::string map_creator, bool is_aday)
	:mapName(map_name), mapCreator(map_creator), is_day(is_aday)
{
	;
}

GameMap::~GameMap()
{
	;
}

std::string GameMap::get_MapName()
{
	return this->mapName;
}

std::string GameMap::get_MapCreator()
{
	return this->mapCreator;
}

bool GameMap::is_dayTime()
{
	return this->is_day;
}

void GameMap::set_MapName(std::string map_name)
{
	this->mapName = map_name;
}

void GameMap::set_MapCreator(std::string map_creator)
{
	this->mapCreator = map_creator;
}

void GameMap::set_isDayTime(bool isAday)
{
	this->is_day = isAday;
}
