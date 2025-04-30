#pragma once
#include "../CT_class/CT_Class.h"
#include "../TerroristClass/TerroristClass.h"
#include "../myrandom/myrandom.h"


class Randomized {
private:
	static const std::vector<string> all_names;
	static std::vector<string> CT_NameData;
	static std::vector<string> Terrorist_NameData;
	static std::vector<Gun> Gun_base_pattern_ASN;

public:


	static std::string get_random_CT(int monye,bool bot);
	static std::string get_random_CT(std::string name, int monye, bool bot);
	static std::string get_random_Terrorist(int monye,bool bot,bool have_bomb);
	static std::string get_random_Terrorist(std::string name,int monye,bool bot,bool have_bomb);

};