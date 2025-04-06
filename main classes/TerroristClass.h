#pragma once
#include <unordered_map>
#include "player.h"
#include <memory>




class Terrorist :public player
{
public:

	Terrorist(string name, int health, int armor, int monye, bool isABot,bool he_have_the_BomB,bool he_Plant_The_Bomb);
	Terrorist();
	Terrorist(const Terrorist&);

	~Terrorist();
	

	//check-getter

	bool haveBomb() const;
	bool plantBomb() const;

	//setter

	void giveABomb(bool);
	void hePlantTheBomb(bool);

	//map_control

	static bool isValidTerrorist(string GUID);

	static std::shared_ptr<Terrorist> get_from_map(string& guid);

	static string add_tomap(std::shared_ptr<Terrorist>);

	static void delete_from_map(string& guid);

	static int get_Terrorist_count();

private:

	static std::unordered_map<string, std::shared_ptr<Terrorist>> Terrorist_map;
	bool haveABomb;
	bool hePlanted;
};