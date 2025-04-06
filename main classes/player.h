#pragma once
#include <string>
#include "myrandom.h"
#include "linked_list_D&R.h"
#include <unordered_map>
#include "Gun.h"

using std::string;


class player {

public:
	player();
	player(string, int, int, int, bool);
	~player();

	//getter

	string get_name() const;
	string get_id() const;
	string get_holdGun_id() const;
	string get_holdGun_name() const;
	int get_health() const;
	int get_armor() const;
	bool is_Alive() const;
	bool is_ABot() const;
	int get_monye() const;

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