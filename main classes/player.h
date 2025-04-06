#pragma once
#include <string>
#include "myrandom.h"
#include "linked_list_D&R.h"
#include <unordered_map>
#include "Gun.h"

using std::string;


class player {

	player();
	player(string, int, int, int, bool);
	~player();

	//getter

	string get_name();
	string get_id();
	string get_holdGun_id();
	string get_holdGun_name();
	int get_health();
	int get_armor();
	bool is_Alive();
	bool is_ABot();
	int get_monye();

	//setter 
	void set_name(string);
	void set_health(int);
	void set_armor(int);
	void set_Alive(bool);
	void set_monye(int);


	//control

	void next_gun();
	void prev_gun();

	void pickGun(string);
	void dropGun(string);

private:

	string name;
	string Guid;
	
	string holdGun_Id;
	string holdGun_Name;

	int health;
	int armor;

	bool isAlive;
	bool isBot;

	int monye;

	DRL_list_Guid GunId_List;

	
};