#include "GameMap.h"

GameMap::GameMap() :GameMap("default", "none", 0)
{
}

GameMap::GameMap(std::string map_name, std::string map_creator, bool is_aday)
	:mapName(map_name), mapCreator(map_creator), is_day(is_aday)
{
	if (map_name == "" || map_creator == "")throw std::invalid_argument("empty string passed");
}

GameMap::GameMap(const GameMap& other)
{
	this->mapName = other.mapName;
	this->mapCreator = other.mapCreator;
	this->is_day = other.is_day;
}

GameMap::~GameMap()
{
	;
}

std::string GameMap::get_MapName() const
{
	return this->mapName;
}

std::string GameMap::get_MapCreator() const
{
	return this->mapCreator;
}

bool GameMap::is_dayTime() const
{
	return this->is_day;
}

void GameMap::set_MapName(std::string map_name)
{
	if (map_name == "")throw std::invalid_argument("empty string passed");
	this->mapName = map_name;
}

void GameMap::set_MapCreator(std::string map_creator)
{
	if (map_creator == "")throw std::invalid_argument("empty string passed");
	this->mapCreator = map_creator;
}

void GameMap::set_isDayTime(bool isAday)
{
	this->is_day = isAday;
}
