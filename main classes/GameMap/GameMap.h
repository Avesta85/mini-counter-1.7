#pragma once
#include <string>
#include <stdexcept>





class GameMap {

public:
	GameMap();
	GameMap(std::string map_name, std::string map_creator, bool is_aday);
	GameMap(const GameMap&);
	~GameMap();

	//getter

	std::string get_MapName() const;
	std::string get_MapCreator() const;
	bool is_dayTime() const;

	//setter

	void set_MapName(std::string);
	void set_MapCreator(std::string);
	void set_isDayTime(bool);



private:

	std::string mapName;
	std::string mapCreator;
	bool is_day;
};