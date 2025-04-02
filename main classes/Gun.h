#pragma once
#include <string>
#include "GunModel.h"



class Gun {
public:
	

	//constructor
	Gun();
	Gun(GunModel::Model _model, int _ammo, int _ammo_Power, int _price);
	Gun(const Gun&);
	
	//distructor
	
	~Gun();

	//Getter

	static int  get_gun_count();

	int get_id();

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

private:

	static int Gun_count;

	int id;
	GunModel::Model model;

	int ammo;
	int ammo_power;

	
	int price;




};