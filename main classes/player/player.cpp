#include "player.h"


player::player():player("unKnown",1,0,0,0)
{
}
player::player(string _name, int _health, int _armor, int _monye, bool _isABot)
	:name(_name),isBot(_isABot)
{
	this->health = (_health > 0) ? _health : 0;
	this->armor = (_armor > 0) ? _armor : 0;
	this->monye = (_monye > 0) ? _monye : 0;
	

	this->isAlive = (health) ? true : false;
	this->Guid = mrand::GuidGen();

	this->holdGun_Id ="";
	this->holdGun_Name = "";

}

player::~player()
{
	;
}

string player::get_name() const
{
	return this->name;
}

string player::get_id() const
{
	return this->Guid;
}

string player::get_holdGun_id() const
{
	return this->holdGun_Id;
}

string player::get_holdGun_name() const
{
	return this->holdGun_Name;
}

int player::get_health() const
{
	return this->health;
}

int player::get_armor() const
{
	return this->armor;
}

bool player::is_Alive() const
{
	return this->isAlive;
}

bool player::is_ABot() const
{
	return this->isBot;
}

int player::get_monye() const
{
	return this->monye; 
}

int player::get_total_Gun_power()
{
	
	int total_power{};
	if (GunId_List.get_size() > 0) {
		auto cur = GunId_List.get_cur();
		auto tmp = GunId_List.get_cur();

		auto&& cur_gun = Gun::get_from_map(cur);

		total_power = total_power + cur_gun->get_ammo() + cur_gun->get_ammo_power();

		cur = GunId_List.go_next();
		while (cur != tmp) {
			cur_gun = Gun::get_from_map(cur);
			total_power = total_power + cur_gun->get_ammo() + cur_gun->get_ammo_power();
			cur = GunId_List.go_next();
		}

	}
	return total_power;
}

void player::set_name(string newName)
{
	this->name = newName;
}

void player::set_health(int newHealth)
{
	this->health=(newHealth > 0) ? newHealth : 0;

	this->isAlive = (health) ? true : false;
}

void player::set_armor(int newArmor)
{
	this->armor = (newArmor > 0) ? newArmor : 0;

}

void player::set_Alive(bool _isAlive)
{
	this->isAlive = _isAlive;
	health = (isAlive) ? health : 0;
}

void player::set_monye(int newMonye)
{
	this->monye = (newMonye > 0) ? newMonye : 0;
}

void player::next_gun()
{
	if (GunId_List.get_size() > 0) {
		this->holdGun_Id = GunId_List.go_next();
		this->holdGun_Id = Gun::get_from_map(this->holdGun_Id)->get_model_name();
	}
}

void player::prev_gun()
{
	if (GunId_List.get_size() > 0) {
		this->holdGun_Id = GunId_List.go_prev();
		this->holdGun_Id = Gun::get_from_map(this->holdGun_Id)->get_model_name();

	}
}

void player::pickGun(string gun_GUID)
{
	if (Gun::isValidGun(gun_GUID)) {
		GunId_List.pick(gun_GUID);
		this->holdGun_Id = GunId_List.get_cur();
		this->holdGun_Name = Gun::get_from_map(this->holdGun_Id)->get_model_name();

	}
	else
		throw std::invalid_argument("Gun ID is not Vailid");
}

void player::dropGun(string gun_GUID)
{
	
	if (Gun::isValidGun(gun_GUID)) {
		GunId_List.drop(gun_GUID);

		if (GunId_List.get_size() > 0) {
			this->holdGun_Id = GunId_List.get_cur();
			this->holdGun_Name = Gun::get_from_map(this->holdGun_Id)->get_model_name();
		}
		else {
			this->holdGun_Id = "";
			this->holdGun_Name = "";
		}
	}
	else
		throw std::invalid_argument("Gun ID is not Vailid");
}

