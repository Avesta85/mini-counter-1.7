#pragma once
#include <string>






class GameMap {

public:

	GameMap(std::string, std::string,bool);
	~GameMap();

	//getter

	std::string get_MapName();
	std::string get_MapCreator();
	bool is_dayTime();

	//setter

	void set_MapName(std::string);
	void set_MapCreator(std::string);
	void set_isDayTime(bool);



private:

	std::string mapName;
	std::string mapCreator;
	bool is_day;
};