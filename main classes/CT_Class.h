#pragma once
#include <unordered_map>
#include "player.h"
#include <memory>




class CT :public player
{
public:

	CT(string name, int health, int armor, int monye, bool isABot, bool he_have_the_BomB, bool he_Plant_The_Bomb);
	CT();
	CT(const CT&);

	~CT();


	//check-getter

	bool haveKit() const;
	bool defusingBomb() const;

	//setter

	void giveAKit(bool);
	void heDefusingTheBomb(bool);

	//map_control

	static bool isValidCT(string GUID);

	static std::shared_ptr<CT> get_from_map(string& guid);

	static string add_tomap(std::shared_ptr<CT>);

	static void delete_from_map(string& guid);

	static int get_CT_count();

private:

	static std::unordered_map<string, std::shared_ptr<CT>> CT_map;
	bool haveAKit;
	bool isheDefusingTheBomb;
};