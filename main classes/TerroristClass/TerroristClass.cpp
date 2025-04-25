#include "TerroristClass.h"

std::unordered_map<string, std::shared_ptr<Terrorist>> Terrorist::Terrorist_map;

Terrorist::Terrorist(string name, int health, int armor, int monye, bool isABot, bool have_BomB, bool he_Plant_The_Bomb=0)
	:player(name, health, armor, monye, isABot), haveABomb(have_BomB), hePlanted(he_Plant_The_Bomb)
{
	;
}

Terrorist::Terrorist()
	:Terrorist("unknown", 1, 0, 0, 1, 0, 0)
{
}

Terrorist::Terrorist(const Terrorist& other)
	:player(other.get_name(), other.get_health(), other.get_armor(), other.get_monye(), other.is_ABot()),haveABomb(other.haveBomb())
		,hePlanted(other.plantBomb())
{
}

Terrorist::~Terrorist()
{
	;
}

bool Terrorist::haveBomb() const
{
	return this->haveABomb;
}

bool Terrorist::plantBomb() const
{
	return this->hePlanted;
}

void Terrorist::giveABomb(bool val)
{
	this->haveABomb = val;
}

void Terrorist::hePlantTheBomb(bool val)
{
	this->hePlanted = val;
}

bool Terrorist::isValidTerrorist(string GUID)
{
	if (Terrorist_map.find(GUID) == Terrorist_map.end())
		return false;

	return true;
}

std::shared_ptr<Terrorist> Terrorist::get_from_map(string& guid)
{
	auto&& cur = Terrorist_map.find(guid);
	if (cur != Terrorist_map.end())
		return cur->second;

	return nullptr;

}

string Terrorist::add_tomap(std::shared_ptr<Terrorist> Terrorist_ptr)
{
	if (Terrorist_map.find(Terrorist_ptr->get_id()) == Terrorist_map.end()) {
		Terrorist_map[Terrorist_ptr->get_id()] = Terrorist_ptr;
	}

	return Terrorist_ptr->get_id();
}

void Terrorist::delete_from_map(string& guid)
{
	auto&& cur = Terrorist_map.find(guid);
	if (cur != Terrorist_map.end())
		Terrorist_map.erase(cur);

}

int Terrorist::get_Terrorist_count()
{
	return Terrorist_map.size();
}


