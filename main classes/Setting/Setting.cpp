#include "Setting.h"

Setting::Setting() :CT_number(0), Terror_number(0), is_player_ct(0)
{
	Map_list.push_back(std::make_shared<GameMap>("de_dust2", "Dave Johnston", 1));
	Map_list.push_back(std::make_shared<GameMap>("de_nuke", "Chris Auty (BubkeZ)", 1));
	Map_list.push_back(std::make_shared<GameMap>("de_inferno", "Chris Auty (BubkeZ)", 1));
	Map_list.push_back(std::make_shared<GameMap>("de_cache", "FMPONE Snelling", 1));
	Map_list.push_back(std::make_shared<GameMap>("de_seaside", "Shawn \"FMPONE\" Snelling", 0));
}

Setting::~Setting()
{
	;
}

std::vector<std::shared_ptr<GameMap>>& Setting::get_map_list()
{
	return Map_list;
}

std::vector<std::string>& Setting::get_CT_list()
{
	return CT_list;
}

std::vector<std::string>& Setting::get_terror_list()
{
	return terror_list;
}

std::weak_ptr<GameMap> Setting::get_selected_map()
{
	return selected_map;
}

int Setting::get_CT_number()
{
	return CT_number;
}

int Setting::get_Terror_number()
{
	return Terror_number;
}

bool Setting::get_side_is_CT()
{
	return this->is_player_ct;
} 

void Setting::set_selected_map(int index)
{
	if(index>=0 && index <Map_list.size())
		selected_map = Map_list[index];
}

void Setting::push_CT_back(std::string newct)
{
	CT_list.push_back(newct);
}

void Setting::push_Terror_back(std::string newterror)
{
	terror_list.push_back(newterror);
}

void Setting::set_player_side(bool is_CT)
{
	this->is_player_ct = is_CT;
}

void Setting::set_CT_number(int number)
{
	this->CT_number = number;
}

void Setting::set_terror_number(int number)
{
	this->Terror_number = number;
}

