#pragma once
#include <string>


class GunModel {
public:

	enum class Model {
		unknown = 0,
        AK47,
        M4A1,
        Sniper,
        Shotgun,
        DesertEagle,
        Uzi,
        MP5,
        P90,
        FAMAS,
        SCAR,
        AUG,
        AWP,
        M249,
        RPK,
        M16,
        Glock,
        Beretta,
        Vector,
        Thompson,
        Galil,
        SPAS12,
        MAC10,
        UMP45,
        XM1014,
        SG553,
        Negev,
        PPBizon,
        CZ75,
        FiveSeven,
        Tec9,
        P250,
        Revolver,
        MP7,
        MP9,
        SG550,
        G3SG1,
        M1014,
        MAG7,
        SawedOff,
        DualBerettas,
        P2000,
        USP_S,
        Deagle,
        M60,
        AK74,
        FNMinimi,
        StG44,
        Barrett,
        Kar98k,
        L96A1,
        Type95,
        QBZ95,
        G36,
        VSS,
        Dragunov,
        HK416,
        F2000,
	};


	static std::string to_String(Model model);
};
