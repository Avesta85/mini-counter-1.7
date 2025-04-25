#include "Gun.h"


std::unordered_map<string, std::shared_ptr<Gun>> Gun:: Gun_map;

Gun::Gun()
	:Gun(GunModel::Model::unknown, 0, 0, 0)
{

}

Gun::Gun(GunModel::Model _model, int _ammo, int _ammo_Power, int _price)
	:model(_model), price(_price), ammo(_ammo), ammo_power(_ammo_Power),id(mrand::GuidGen())
{
	if (_price < 0 || _ammo < 0 || _ammo_Power < 0) throw std::invalid_argument("negative argument passed to Gun");
}

Gun::Gun(const Gun& other)
{
	ammo = other.ammo;
	ammo_power = other.ammo_power;
	price = other.price;
	model = other.model;
	
	id = other.id;
}

Gun::~Gun()
{
	;
}

string Gun::get_id()
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
	if (ammo < 0)throw std::invalid_argument("negative ammo count");
	
	this->ammo = ammo;
}

void Gun::set_ammo_power(int ammo_power)
{
	if (ammo_power < 0) throw std::invalid_argument("negative ammo power");
	
	this->ammo_power = ammo_power;
}

void Gun::set_price(int price)
{
	if (price < 0) throw std::invalid_argument("negative price");
	
	this->price = price;
}

bool Gun::isValidGun(string GUID)
{

	if (Gun_map.find(GUID) == Gun_map.end())
		return false;

	return true;
}

std::shared_ptr<Gun> Gun::get_from_map(string& guid)
{

	auto cur = Gun_map.find(guid);
	if(cur != Gun_map.end())
		return cur->second;

	return nullptr;
}

string Gun::add_tomap(std::shared_ptr<Gun> gun_ptr)
{
	if(Gun_map.find(gun_ptr->get_id()) == Gun_map.end())
		Gun_map[gun_ptr->get_id()] = gun_ptr;

	return gun_ptr->get_id();
}

void Gun::delete_from_map(string& guid)
{
	auto cur = Gun_map.find(guid);

	if (cur != Gun_map.end())
		Gun_map.erase(cur);

}

int Gun::get_gun_count() {

	return Gun_map.size();
}
