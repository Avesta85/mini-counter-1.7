#pragma once

#include "../GameMap/GameMap.h"
#include <vector>
#include "../CT_Class/CT_Class.h"
#include "../TerroristClass/TerroristClass.h"
#include "../GameManager/GameManager.h"


class Setting
{
private:
	std::vector<std::shared_ptr<GameMap>> Map_list;
	std::vector<std::string> CT_list;
	std::vector<std::string> terror_list;

	std::weak_ptr<GameMap> selected_map;

	bool is_player_ct;
	int CT_number, Terror_number;

public:

	Setting();
	~Setting();

	// getter

	std::vector<std::shared_ptr<GameMap>>& get_map_list();

	std::vector<std::string>& get_CT_list();

	std::vector<std::string>& get_terror_list();
	
	std::weak_ptr<GameMap> get_selected_map();

	int get_CT_number();
	int get_Terror_number();

	bool get_side_is_CT();
	//setter()

	void set_selected_map(int index);
	
	void push_CT_back(std::string newct);
	
	void push_Terror_back(std::string newterror);

	void set_player_side(bool is_CT);

	void set_CT_number(int number);
	void set_terror_number(int number);

	//build

	
};

