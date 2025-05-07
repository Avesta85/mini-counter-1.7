#include <gtest/gtest.h>
#include "../main classes/TerroristClass/TerroristClass.h"



TEST(TerroristTest, ConstructorWithValidParameters) {
    Terrorist t("Ali", 80, 20, 3000, true, true, false);

    EXPECT_EQ(t.get_name(), "Ali");
    EXPECT_EQ(t.get_armor(), 20);
    EXPECT_TRUE(t.haveBomb());
    EXPECT_FALSE(t.plantBomb());
}

TEST(TerroristTest, DefaultConstructor) {
    Terrorist t;

    EXPECT_EQ(t.get_name(), "unknown");
    EXPECT_EQ(t.get_health(), 1);
    EXPECT_FALSE(t.haveBomb());
    EXPECT_FALSE(t.plantBomb());
}


TEST(TerroristTest, ToggleBombStatus) {
    Terrorist t("Bomber", 50, 10, 200, false, true, false);
    t.hePlantTheBomb(true);

    EXPECT_TRUE(t.plantBomb());
}

//error
TEST(TerroristTest, AddAndRemoveFromMap) {
    auto t = std::make_shared<Terrorist>("T1", 90, 30, 1000, true, false, true);
    string tGuid = Terrorist::add_tomap(t);

    EXPECT_TRUE(Terrorist::isValidTerrorist(tGuid));
    EXPECT_EQ(Terrorist::get_Terrorist_count(), 1);

    Terrorist::delete_from_map(tGuid);
    EXPECT_FALSE(Terrorist::isValidTerrorist(tGuid));
}

TEST(TerroristTest, AccessInvalidTerrorist) {
    std::string invalidGuid = "invalid_456";
    auto t = Terrorist::get_from_map(invalidGuid);

    EXPECT_EQ(t, nullptr);
}
