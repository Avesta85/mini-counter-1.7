#include "CT_Class.h"

std::unordered_map<string, std::shared_ptr<CT>> CT::CT_map;

CT::CT(string name, int health, int armor, int monye, bool isABot, bool have_Kit, bool he_defusingTheBomb=0)
	:player(name, health, armor, monye, isABot), haveAKit(have_Kit), isheDefusingTheBomb(he_defusingTheBomb)
{
	;
}

CT::CT()
	:CT("unknown", 1, 0, 0, 1, 0, 0)
{
	;
}

CT::CT(const CT& other)
	:player(other.get_name(), other.get_health(), other.get_armor(), other.get_monye(), other.is_ABot()), haveAKit(other.haveKit())
	, isheDefusingTheBomb(other.defusingBomb())
{
}

CT::~CT()
{
	;
}

bool CT::haveKit() const
{
	return this->haveAKit;
}

bool CT::defusingBomb() const
{
	return this->isheDefusingTheBomb;
}

void CT::giveAKit(bool val)
{
	this->haveAKit = val;
}

void CT::heDefusingTheBomb(bool val)
{
	this->isheDefusingTheBomb = val;
}

bool CT::isValidCT(string GUID)
{
	if (CT_map.find(GUID) == CT_map.end())
		return false;

	return true;
}

std::shared_ptr<CT> CT::get_from_map(string& guid)
{
	auto&& cur = CT_map.find(guid);
	if (cur != CT_map.end())
		return cur->second;

	return nullptr;
}

string CT::add_tomap(std::shared_ptr<CT>CT_ptr)
{
	if (CT_map.find(CT_ptr->get_id()) == CT_map.end()) {
		CT_map[CT_ptr->get_id()] = CT_ptr;
	}

	return CT_ptr->get_id();
}

void CT::delete_from_map(string& guid)
{
	auto&& cur = CT_map.find(guid);
	if (cur != CT_map.end())
		CT_map.erase(cur);

}

int CT::get_CT_count()
{
	return CT_map.size();
}


