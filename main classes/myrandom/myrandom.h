#pragma once
#include <array>
#include <random>
#include <format>
#include <sstream>
#include <string>
#include <iomanip>
#include <algorithm>
//#include "../Gun/Gun.h"

class Gun;

namespace mrand {
	std::string GuidGen();

	int Random_number(int start, int end);

	void Shuffle_GunVector(std::vector<Gun>& vec);
}
