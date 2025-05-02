#include <gtest/gtest.h>
#include "../main classes/Gun/Gun.h"





TEST(GunTest, ConstructorWithValidParameters) {
    Gun gun(GunModel::Model::AK47, 100, 50, 2000);

    EXPECT_EQ(gun.get_model(), GunModel::Model::AK47);
    EXPECT_EQ(gun.get_ammo(), 100);
    EXPECT_EQ(gun.get_ammo_power(), 50);
    EXPECT_EQ(gun.get_price(), 2000);
    EXPECT_FALSE(gun.get_id().empty());
}

TEST(GunTest, AddAndRetrieveFromMap) {
    auto gun = std::make_shared<Gun>(GunModel::Model::M4A1, 150, 30, 1500);
    string guid1 = Gun::add_tomap(gun);

    EXPECT_TRUE(Gun::isValidGun(guid1));
    EXPECT_EQ(Gun::get_gun_count(), 1);

    auto retrieved = Gun::get_from_map(guid1);
    ASSERT_NE(retrieved, nullptr);
    EXPECT_EQ(retrieved->get_model_name(), "M4A1");
    Gun::delete_from_map(guid1);
}

//edge
TEST(GunTest, ZeroValuesInConstructor) {

    Gun gun(GunModel::Model::AK47, 0, 0, 0);
    EXPECT_EQ(gun.get_ammo(), 0);
    EXPECT_EQ(gun.get_price(), 0);
}

TEST(GunTest, MaxIntValues) {
    int maxVal = std::numeric_limits<int>::max(); // in braye ine ke shayad ye cast bad bashe chat zadam goft behtare inam bashe
    Gun gun(GunModel::Model::Sniper, maxVal, maxVal, maxVal);

    EXPECT_EQ(gun.get_ammo(), maxVal);
    EXPECT_EQ(gun.get_price(), maxVal);
}

//constructor test
TEST(GunTest, NegativeParametersInConstructor) {
    EXPECT_THROW(
        Gun gun(GunModel::Model::unknown, -1, 10, 100),
        std::invalid_argument
    );

    EXPECT_THROW(
        Gun gun(GunModel::Model::unknown, 10, -5, 100),
        std::invalid_argument
    );

    EXPECT_THROW(
        Gun gun(GunModel::Model::unknown, 10, 10, -100),
        std::invalid_argument
    );
}

TEST(GunTest, SetInvalidAmmo) {
    Gun gun;
    EXPECT_THROW(gun.set_ammo(-5), std::invalid_argument);
}

TEST(GunTest, DeleteNonExistentGunFromMap) {
    std::string invalidGuid = "invalid_123";
    EXPECT_FALSE(Gun::isValidGun(invalidGuid));
    Gun::delete_from_map(invalidGuid);
    EXPECT_EQ(Gun::get_gun_count(), 0);
}