#include "../main classes/player/player.h"
#include <gtest/gtest.h>



// مقدار دهی پیش فرض
TEST(PlayerTest, DefaultConstructorTest) {
    player p;
    EXPECT_EQ(p.get_name(), "unKnown");
    EXPECT_EQ(p.get_health(), 1);
    EXPECT_EQ(p.get_armor(), 0);
    EXPECT_EQ(p.get_monye(), 0);
    EXPECT_TRUE(p.is_Alive());
    EXPECT_FALSE(p.is_ABot());
}

// کانستراکتور با مقادیر دستی
TEST(PlayerTest, ParameterizedConstructor_ValidInput) {
    player p("Ali", 100, 50, 200, true);
    EXPECT_EQ(p.get_name(), "Ali");
    EXPECT_EQ(p.get_health(), 100);
    EXPECT_EQ(p.get_armor(), 50);
    EXPECT_EQ(p.get_monye(), 200);
    EXPECT_TRUE(p.is_Alive());
    EXPECT_TRUE(p.is_ABot());
}

// مقادیر منفی باید هندل بشه و به مقادیر صفر تبدیل بشه 
TEST(PlayerTest, ParameterizedConstructor_InvalidInput) {
    player p("Bot", -10, -5, -30, false);
    EXPECT_EQ(p.get_health(), 0);
    EXPECT_EQ(p.get_armor(), 0);
    EXPECT_EQ(p.get_monye(), 0);
    EXPECT_FALSE(p.is_Alive());
}

// زنده بودن و ارتباطش با مقدار سلامتی
TEST(PlayerTest, SetHealth_Valid) {
    player p;
    p.set_health(70);
    EXPECT_EQ(p.get_health(), 70);
    EXPECT_TRUE(p.is_Alive());
}

// سلامتی صفر یعنی اون فرد مرده
TEST(PlayerTest, SetHealth_Invalid) {
    player p;
    p.set_health(-5);
    EXPECT_EQ(p.get_health(), 0);
    EXPECT_FALSE(p.is_Alive());
}

// اگه بمیره باید سلامتیش فورا صفر بشه
TEST(PlayerTest, SetAliveChangesHealth) {
    player p("Test", 30, 10, 100, false);
    p.set_Alive(false);
    EXPECT_FALSE(p.is_Alive());
    EXPECT_EQ(p.get_health(), 0);
}

// تغییر اسم
TEST(PlayerTest, SetNameTest) {
    player p;
    p.set_name("Reza");
    EXPECT_EQ(p.get_name(), "Reza");
}

// هندل کردن پول منفی و تبدیلش به صفر
TEST(PlayerTest, SetMoneyInvalid) {
    player p;
    p.set_monye(-100);
    EXPECT_EQ(p.get_monye(), 0);
}


//تست برداشتن تفنگ
TEST(PlayerTest, PickGunValid) {
    player p;
    string test_gun = Gun::add_tomap(std::make_shared<Gun>(GunModel::Model::AK47,20,2,2000));

    p.pickGun(test_gun);
    // اون گانی که برمیداره باید بیاد دستش
    EXPECT_EQ(p.get_holdGun_id(), test_gun);
    EXPECT_EQ(p.get_holdGun_name(), "AK-47");
}

// باید تفنگ رو بندازه
TEST(PlayerTest, DropAllGuns) {
    player p;

    string test_gun = Gun::add_tomap(std::make_shared<Gun>(GunModel::Model::AK47, 20, 2, 2000));

    p.pickGun(test_gun);
    EXPECT_FALSE(p.get_holdGun_id().empty());

    p.dropGun(test_gun); // بعد انداخت باید خالی بشه
    EXPECT_TRUE(p.get_holdGun_id().empty());
    EXPECT_TRUE(p.get_holdGun_name().empty());
}



TEST(PlayerTest, DropOrPickInvalidGun) {
    player p;
    string tmp_gun = "hello";
    // تفنگ نامعتبر رو نمیشه برداشت
    EXPECT_THROW(p.pickGun(tmp_gun), std::invalid_argument);
    // تفنگی که تو دستت نیست رو نمیشه انداخت
    EXPECT_THROW(p.dropGun(tmp_gun), std::invalid_argument);
}