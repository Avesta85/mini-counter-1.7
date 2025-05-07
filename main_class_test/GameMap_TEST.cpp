#include <gtest/gtest.h>
#include "../main classes/GameMap/GameMap.h"



TEST(GameMapTest, ConstructorWithValidParameters) {
    GameMap map("Forest", "Player1", true);

    EXPECT_EQ(map.get_MapName(), "Forest");
    EXPECT_EQ(map.get_MapCreator(), "Player1");
    EXPECT_TRUE(map.is_dayTime());
}

TEST(GameMapTest, DefaultConstructor) {
    GameMap map;

    EXPECT_EQ(map.get_MapName(), "default");
    EXPECT_EQ(map.get_MapCreator(), "none");
    EXPECT_FALSE(map.is_dayTime());
}

TEST(GameMapTest, CopyConstructor) {
    GameMap original("City", "Admin", false);
    GameMap copied(original);

    EXPECT_EQ(copied.get_MapName(), "City");
    EXPECT_EQ(copied.get_MapCreator(), "Admin");
    EXPECT_FALSE(copied.is_dayTime());
}

//edge
TEST(GameMapTest, EmptyStringsInConstructor) {
    EXPECT_THROW(
        GameMap("", "Creator", true),
        std::invalid_argument
    );

    EXPECT_THROW(
        GameMap("MapName", "", false),
        std::invalid_argument
    );
}

TEST(GameMapTest, ToggleDayNightStatus) {
    GameMap map("Desert", "User", true);
    map.set_isDayTime(false);
    EXPECT_FALSE(map.is_dayTime());

    map.set_isDayTime(true);
    EXPECT_TRUE(map.is_dayTime());
}

TEST(GameMapTest, SetEmptyMapName) {
    GameMap map;
    EXPECT_THROW(map.set_MapName(""), std::invalid_argument);
}

TEST(GameMapTest, SetEmptyMapCreator) {
    GameMap map;
    EXPECT_THROW(map.set_MapCreator(""), std::invalid_argument);
}
