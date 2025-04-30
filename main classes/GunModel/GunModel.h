#pragma once
#include <string>


class GunModel {
public:

	enum class Model {
		unknown = 0,
		AK47,
		M4A1,
		Sniper,
		Shotgun
	};


	static std::string to_String(Model model);
};
