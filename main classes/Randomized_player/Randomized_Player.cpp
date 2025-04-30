#include "Randomized_Player.h"

const std::vector<std::string> Randomized::all_names = {
    "John", "Kelly", "Alex", "Liam", "Sophia", "Olivia", "Mason", "Ava", "Ethan", "Isabella",
    "James", "Mia", "Benjamin", "Charlotte", "Lucas", "Amelia", "Henry", "Harper", "Alexander", "Evelyn",
    "Michael", "Abigail", "Daniel", "Emily", "Matthew", "Ella", "Joseph", "Elizabeth", "Samuel", "Camila",
    "David", "Luna", "Carter", "Sofia", "Owen", "Avery", "Wyatt", "Mila", "Jack", "Aria",
    "Luke", "Scarlett", "Jayden", "Penelope", "Dylan", "Layla", "Grayson", "Chloe", "Levi", "Victoria",
    "Isaac", "Madison", "Gabriel", "Eleanor", "Julian", "Grace", "Mateo", "Nora", "Anthony", "Riley",
    "Jaxon", "Zoey", "Lincoln", "Hannah", "Joshua", "Hazel", "Christopher", "Lily", "Andrew", "Ellie",
    "Theodore", "Violet", "Caleb", "Lillian", "Ryan", "Zoe", "Asher", "Stella", "Nathan", "Aurora",
    "Thomas", "Natalie", "Leo", "Emilia", "Isaiah", "Everly", "Charles", "Leah", "Josiah", "Aubrey",
    "Hudson", "Willow", "Christian", "Addison", "Hunter", "Lucy", "Connor", "Audrey", "Eli", "Bella",
    "Ezra", "Savannah", "Aaron", "Claire", "Landon", "Skylar", "Adrian", "Isla", "Jonathan", "Paisley",
    "Nolan", "Genesis", "Jeremiah", "Naomi", "Easton", "Elena", "Ezekiel", "Caroline", "Colton", "Eliana",
    "Cameron", "Anna", "Aaron", "Serenity", "Angel", "Kennedy", "Roman", "Gabriella", "Miles", "Allison",
    "Robert", "Maya", "Jameson", "Autumn", "Nicholas", "Quinn", "Greyson", "Nevaeh", "Cooper", "Piper",
    "Ian", "Ruby", "Carson", "Alice", "Axel", "Sadie", "Jaxson", "Hailey", "Dominic", "Eva",
    "Giovanni", "Adeline", "Everett", "Hailey", "Brooks", "Ariana", "Xavier", "Josephine", "Kai", "Cora",
    "Parker", "Vivian", "Adam", "Madelyn", "Jace", "Rylee", "Wesley", "Brielle", "Kayden", "Clara",
    "Silas", "Raelynn", "Jason", "Liliana", "Declan", "Samantha", "Micah", "Sophie", "Brayden", "Delilah",
    "Weston", "Eva", "Vincent", "Arya", "Miles", "Emery", "Antonio", "Lydia", "Abel", "Jade",
    "Emmett", "Peyton", "Sawyer", "Brynlee", "Braxton", "Clara", "Ryder", "Hadley", "Myles", "Melanie"
};
std::vector<Gun> Randomized::Gun_base_pattern_ASN = {
    Gun(GunModel::Model::AK47,         60,  10, 100),
    Gun(GunModel::Model::M4A1,         60,  20, 200),
    Gun(GunModel::Model::Shotgun,      30,  50, 400),
    Gun(GunModel::Model::Sniper,       20, 150, 700),
    Gun(GunModel::Model::DesertEagle,  7,   80, 300),
    Gun(GunModel::Model::Uzi,          80,  12, 150),
    Gun(GunModel::Model::MP5,          70,  15, 180),
    Gun(GunModel::Model::P90,          90,  13, 170),
    Gun(GunModel::Model::FAMAS,        60,  25, 220),
    Gun(GunModel::Model::SCAR,         40,  40, 350),
    Gun(GunModel::Model::AUG,          50,  30, 300),
    Gun(GunModel::Model::AWP,          10, 200, 800),
    Gun(GunModel::Model::M249,        100, 20, 500),
    Gun(GunModel::Model::RPK,          80,  25, 450),
    Gun(GunModel::Model::M16,          60,  22, 210),
    Gun(GunModel::Model::Glock,        15,  10, 90),
    Gun(GunModel::Model::Beretta,      17,  12, 110),
    Gun(GunModel::Model::Vector,       50,  18, 200),
    Gun(GunModel::Model::Thompson,     50,  20, 220),
    Gun(GunModel::Model::Galil,        60,  22, 230),
    Gun(GunModel::Model::SPAS12,       8,   70, 400),
    Gun(GunModel::Model::MAC10,        60,  13, 160),
    Gun(GunModel::Model::UMP45,        60,  18, 190),
    Gun(GunModel::Model::XM1014,       7,   65, 420),
    Gun(GunModel::Model::SG553,        60,  28, 280),
    Gun(GunModel::Model::Negev,       120, 18, 550),
    Gun(GunModel::Model::PPBizon,      64,  10, 140),
    Gun(GunModel::Model::CZ75,         12,  15, 120),
    Gun(GunModel::Model::FiveSeven,    20,  17, 130),
    Gun(GunModel::Model::Tec9,         18,  18, 150),
    Gun(GunModel::Model::P250,         13,  20, 150),
    Gun(GunModel::Model::Revolver,      8,  90, 350),
    Gun(GunModel::Model::MP7,          50,  15, 175),
    Gun(GunModel::Model::MP9,          60,  12, 160),
    Gun(GunModel::Model::SG550,        50,  35, 320),
    Gun(GunModel::Model::G3SG1,        40,  40, 400),
    Gun(GunModel::Model::M1014,         7,  70, 430),
    Gun(GunModel::Model::MAG7,          5,  85, 410),
    Gun(GunModel::Model::SawedOff,      6,  75, 390),
    Gun(GunModel::Model::DualBerettas, 30,  13, 160),
    Gun(GunModel::Model::P2000,        13,  15, 140),
    Gun(GunModel::Model::USP_S,        12,  17, 150),
    Gun(GunModel::Model::Deagle,        7,  85, 300),
    Gun(GunModel::Model::M60,         100, 22, 520),
    Gun(GunModel::Model::AK74,         60,  24, 210),
    Gun(GunModel::Model::FNMinimi,    100, 20, 500),
    Gun(GunModel::Model::StG44,        50,  27, 270),
    Gun(GunModel::Model::Barrett,      10, 220, 850),
    Gun(GunModel::Model::Kar98k,        5, 180, 750),
    Gun(GunModel::Model::L96A1,         7, 190, 780),
    Gun(GunModel::Model::Type95,       60,  26, 260),
    Gun(GunModel::Model::QBZ95,        60,  24, 250),
    Gun(GunModel::Model::G36,          60,  23, 240),
    Gun(GunModel::Model::VSS,          10, 120, 600),
    Gun(GunModel::Model::Dragunov,     10, 150, 650),
    Gun(GunModel::Model::HK416,        60,  25, 270),
    Gun(GunModel::Model::F2000,        50,  28, 280)

};



std::vector<std::string> Randomized::CT_NameData = std::vector<std::string>(all_names.begin(), all_names.begin() + 100);
std::vector<std::string> Randomized::Terrorist_NameData = std::vector<std::string>(all_names.begin() + 100, all_names.end());


std::string Randomized::get_random_CT(int monye, bool bot)
{
    int name_index = mrand::Random_number(0, 99);
    int random_health = mrand::Random_number(700, 1200);
    int random_armor = mrand::Random_number(0, 700);
    bool have_kit = mrand::Random_number(0, 1);
    
    std::string guid_tmp = CT::add_tomap(std::make_shared<CT>(CT_NameData[name_index],random_health,random_armor,monye,bot,have_kit,0));

    auto&& player = CT::get_from_map(guid_tmp);

    int monye_tmp = monye;

    mrand::Shuffle_GunVector(Gun_base_pattern_ASN);
    for (auto g : Gun_base_pattern_ASN) {
        if (monye_tmp >= g.get_price()) {

            string gun_tmp = Gun::add_tomap(std::make_shared<Gun>(g));
            player->pickGun(gun_tmp);
            monye -= g.get_price();
        }
        if (monye < 100) {
            break;
        }
    }
    player->set_monye(monye_tmp);
    return guid_tmp;
}

std::string Randomized::get_random_CT(std::string name, int monye, bool bot)
{
    int random_health = mrand::Random_number(700, 1200);
    int random_armor = mrand::Random_number(0, 700);
    bool have_kit = mrand::Random_number(0, 1);

    std::string guid_tmp = CT::add_tomap(std::make_shared<CT>(name, random_health, random_armor, monye, bot, have_kit, 0));

    auto&& player = CT::get_from_map(guid_tmp);

    int monye_tmp = monye;

    mrand::Shuffle_GunVector(Gun_base_pattern_ASN);
    for (auto g : Gun_base_pattern_ASN) {
        if (monye_tmp >= g.get_price()) {

            string gun_tmp = Gun::add_tomap(std::make_shared<Gun>(g));
            player->pickGun(gun_tmp);
            monye -= g.get_price();
        }
        if (monye < 100) {
            break;
        }
    }
    player->set_monye(monye_tmp);
    return guid_tmp;
}

std::string Randomized::get_random_Terrorist(int monye, bool bot,bool have_bomb)
{
    int name_index = mrand::Random_number(0, 99);
    int random_health = mrand::Random_number(700, 1200);
    int random_armor = mrand::Random_number(0, 700);
    

    std::string guid_tmp = Terrorist::add_tomap(std::make_shared<Terrorist>(Terrorist_NameData[name_index], random_health, random_armor, monye, bot, have_bomb, 0));

    auto&& player = Terrorist::get_from_map(guid_tmp);

    int monye_tmp = monye;
    mrand::Shuffle_GunVector(Gun_base_pattern_ASN);
    for (auto g : Gun_base_pattern_ASN) {
        if (monye_tmp >= g.get_price()) {

            string gun_tmp = Gun::add_tomap(std::make_shared<Gun>(g));
            player->pickGun(gun_tmp);
            monye -= g.get_price();
        }
        if (monye < 100) {
            break;
        }
    }
    player->set_monye(monye_tmp);
    return guid_tmp;
}

std::string Randomized::get_random_Terrorist(std::string name, int monye, bool bot, bool have_bomb)
{

    int random_health = mrand::Random_number(700, 1200);
    int random_armor = mrand::Random_number(0, 700);


    std::string guid_tmp = Terrorist::add_tomap(std::make_shared<Terrorist>(name, random_health, random_armor, monye, bot, have_bomb, 0));

    auto&& player = Terrorist::get_from_map(guid_tmp);

    int monye_tmp = monye;
    mrand::Shuffle_GunVector(Gun_base_pattern_ASN);
    for (auto g : Gun_base_pattern_ASN) {
        if (monye_tmp >= g.get_price()) {

            string gun_tmp = Gun::add_tomap(std::make_shared<Gun>(g));
            player->pickGun(gun_tmp);
            monye -= g.get_price();
        }
        if (monye < 100) {
            break;
        }
    }
    player->set_monye(monye_tmp);
    return guid_tmp;
}
