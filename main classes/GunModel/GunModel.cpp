#include "GunModel.h"


std::string GunModel::to_String(Model model)
{
	{
		switch (model) {

		case Model::AK47:   return "AK-47";

		case Model::M4A1:   return "M4A1";

		case Model::Sniper: return "Sniper Rifle";

		case Model::Shotgun: return "Shotgun";

		default: return "Unknown";

		}

	}
}
