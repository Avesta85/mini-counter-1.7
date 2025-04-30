#include "myrandom.h"
#include "../Gun/Gun.h"
std::string mrand::GuidGen()
{
	std::random_device base;

	std::mt19937 random_num(base());

	std::uniform_int_distribution<uint32_t> dist32(0, 0xffffffff);

	std::uniform_int_distribution<uint16_t> dist16(0, 0xffff);

	uint32_t part1 = dist32(random_num);
	uint16_t part2 = dist16(random_num);
	uint16_t part3 = (dist16(random_num) & 0x0fff) | 0x4000;
	uint16_t part4 = (dist16(random_num) & 0x3fff) | 0x8000;
	uint32_t part51 = dist32(random_num);
	uint16_t part52 = dist16(random_num);


	std::stringstream ss;

	ss << std::hex << std::setfill('0')
		<< std::setw(8) << part1 << "-"
		<< std::setw(4) << part2 << "-"
		<< std::setw(4) << part3 << "-"
		<< std::setw(4) << part4 << "-"
		<< std::setw(8) << part51 << std::setw(4) << part52;

	return ss.str();
}

int mrand::Random_number(int start, int end)
{
	static std::random_device rd;
	static std::mt19937 gen(rd());
	std::uniform_int_distribution<> distrib(start, end);

	return distrib(gen);
}

void mrand::Shuffle_GunVector(std::vector<Gun>& guns) {

	static std::random_device rd;
	static std::mt19937 gen(rd());
	int n = guns.size();

	for (int i = n - 1; i > 0; --i) {
		std::uniform_int_distribution<> dis(0, i);
		int j = dis(gen);

		if (i != j) {
			Gun temp = guns[i];
			guns[i] = guns[j];
			guns[j] = temp;
		}
	}
}