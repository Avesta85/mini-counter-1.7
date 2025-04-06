#pragma once
#include <string>
#include <memory>
#include "myrandom.h"
#include <unordered_map>
#include "GunModel.h"
using std::string;


class Gun {
public:
	

	//constructor
	Gun();
	Gun(GunModel::Model _model, int _ammo, int _ammo_Power, int _price);
	Gun(const Gun&);
	
	//distructor
	
	~Gun();

	//Getter

	// tedad gun ro ba size map migirim

	string get_id();

	GunModel::Model get_model() const;

	std::string get_model_name() const;

	int get_ammo() const;

	int get_ammo_power() const;

	int get_price() const;

	// setter

	void set_model(GunModel::Model);
	void set_ammo(int);
	void set_ammo_power(int);
	void set_price(int);

	// map

	static bool isValidGun(string GUID);
	
	static std::shared_ptr<Gun> get_from_map(string& guid);

	static string add_tomap(std::shared_ptr<Gun>);

	static void delete_from_map(string& guid);

	static int get_gun_count();

private:

	

	static std::unordered_map<string, std::shared_ptr<Gun>> Gun_map;
	string id;
	GunModel::Model model;

	int ammo;
	int ammo_power;

	
	int price;




};