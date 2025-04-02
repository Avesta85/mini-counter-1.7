#include "Gun.h"

int Gun::Gun_count = 0;


Gun::Gun()
	:model(GunModel::Model::unknown),price(0),ammo(0),ammo_power(0),id(Gun::Gun_count + 1)
{
	Gun::Gun_count++;
}

Gun::Gun(GunModel::Model _model, int _ammo, int _ammo_Power, int _price)
	:model(_model), price(_price), ammo(_ammo), ammo_power(_ammo_Power), id(Gun::Gun_count + 1)
{
	Gun::Gun_count++;
}

Gun::Gun(const Gun& other)
{
	ammo = other.ammo;
	ammo_power = other.ammo_power;
	price = other.price;
	model = other.model;
	
	id = ++Gun::Gun_count;
}

Gun::~Gun()
{
	Gun::Gun_count--;
}

int Gun::get_gun_count()
{
	return Gun_count;
}

int Gun::get_id()
{
	return id;
}

GunModel::Model Gun::get_model() const
{
	return model;
}

std::string Gun::get_model_name() const
{
	return GunModel::to_String(model);
}

int Gun::get_ammo() const
{
	return ammo;
}

int Gun::get_ammo_power() const
{
	return ammo_power;
}

int Gun::get_price() const
{
	return price;
}

void Gun::set_model(GunModel::Model model)
{
	this->model = model;
}

void Gun::set_ammo(int ammo)
{
	if (ammo >= 0)
		this->ammo = ammo;
}

void Gun::set_ammo_power(int ammo_power)
{
	if (ammo_power >= 0)
		this->ammo_power = ammo_power;
}

void Gun::set_price(int price)
{
	if (price > 0)
		this->price = price;
}


