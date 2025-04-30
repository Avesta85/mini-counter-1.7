#pragma once

#include ""
#include <vector>
#include "CT_Class.h"
#include "TerroristClass.h"


class Setting
{
private:
	std::vector<std::shared_ptr<GameMap>> Map_list;
	std::vector<CT> CT_list;
	std::vector<Terrorist> terror_list;

	std::weak_ptr<GameMap> selected_map;

	bool is_player_ct;
	int CT_number, Terror_number;

public:

	Setting();
	~Setting();

	// getter

	std::vector<std::shared_ptr<GameMap>>& get_map_list();

	std::vector<CT>& get_CT_list();

	std::vector<Terrorist>& get_terror_list();
	
	std::weak_ptr<GameMap> get_selected_map();

	int get_CT_number();
	int get_Terror_number();

	//setter()

	void set_selected_map(int index);
	
	void push_CT_back(CT& newct);
	
	void push_Terror_back(Terrorist& newterror);

	void set_player_side(bool is_CT);

	void set_CT_number(int number);
	void set_terror_number(int number);
};

