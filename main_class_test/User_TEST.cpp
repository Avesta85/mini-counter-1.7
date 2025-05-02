#include <gtest/gtest.h>
#include "../main classes/User/User.h"

// تست ساخت اولیه و هش پسورد
TEST(UserTest, ConstructorHashesPassword) { 
    User user("ali", "aligator", "myPass123");
    EXPECT_EQ(user.get_username(), "ali");
    EXPECT_EQ(user.get_nickname(), "aligator");
    EXPECT_NE(user.get_hashed_password(), "myPass123");
    EXPECT_EQ(user.get_winCount(), 0);
    EXPECT_EQ(user.get_loseCount(), 0);
}

// تست اینکه هش تابع ثابت هست برای یک پسورد
TEST(UserTest, HashingConsistency) {
    std::string hash1 = User::Hash_SHA_password("test123");
    std::string hash2 = User::Hash_SHA_password("test123");
    EXPECT_EQ(hash1, hash2);
}

// تست مقادیر لبه‌ای: ورودی خیلی بزرگ
TEST(UserTest, LongUsernameAndPassword) {
    std::string long_str(10000, 'a');
    User user(long_str, "nick", long_str);
    EXPECT_EQ(user.get_username(), long_str);
    EXPECT_EQ(user.get_hashed_password().size(), 64); // SHA-256 => 64 hex chars
}

// ساخت کاربر با رکورد بازی
TEST(UserTest, ConstructorWithGameRecord) {
    Gameround g1{ true, true };
    Gameround g2{ false, false };
    std::vector<Gameround> games = { g1, g2 };
    User user("reza", "rezadoo", "1234", 3, 5, games);

    EXPECT_EQ(user.get_username(), "reza");
    EXPECT_EQ(user.get_winCount(), 3);
    EXPECT_EQ(user.get_loseCount(), 5);
    EXPECT_EQ(user.get_gameRecord().size(), 2);
}

// بررسی افزودن رکورد بازی
TEST(UserTest, AddGameRecordWorks) {
    User user("mohsen", "momo", "pass");
    Gameround gr{ false, true };
    user.add_gameRecord(gr);

    auto records = user.get_gameRecord();
    ASSERT_EQ(records.size(), 1);
    EXPECT_TRUE(records[0].won);
    EXPECT_FALSE(records[0].is_CT);
}

// بررسی شمارنده‌ها
TEST(UserTest, WinAndLoseIncrementsCorrectly) {
    User user("test", "test", "pass");
    user.player_win();
    user.player_win();
    user.player_lose();

    EXPECT_EQ(user.get_winCount(), 2);
    EXPECT_EQ(user.get_loseCount(), 1);
}

// خروجی JSON برای کاربر معمولی
TEST(UserTest, ToJsonOutput) {
    User user("ahmad", "nick", "secret");
    user.player_win();
    user.player_lose();

    Gameround gr{ true, true };
    user.add_gameRecord(gr);

    auto j = user.to_json();
    EXPECT_EQ(j["Username"], "ahmad");
    EXPECT_EQ(j["nickname"], "nick");
    EXPECT_EQ(j["wincount"], 1);
    EXPECT_EQ(j["losecount"], 1);
    EXPECT_TRUE(j["game"].is_array());
    EXPECT_EQ(j["game"].size(), 1);
}

// تست کاربر بدون بازی
TEST(UserTest, EmptyGameRecord) {
    User user("tina", "tin", "tintin");
    EXPECT_TRUE(user.get_gameRecord().empty());
    EXPECT_EQ(user.to_json()["game"].size(), 0);
}

// پسورد خالی و نال کاراکتر
TEST(UserTest, EmptyAndNullPassword) {
    User u1("ali", "nick", "");
    EXPECT_EQ(u1.get_hashed_password().size(), 64);

    User u2("ali", "nick", std::string("\0", 1));
    EXPECT_EQ(u2.get_hashed_password().size(), 64);
}

// یوزرنیم با یونیکد و کاراکترهای خاص
TEST(UserTest, UnicodeAndSpecialChars) {
    std::string weird_username = "سعید😊\n\t";
    User user(weird_username, "nick", "pass");

    EXPECT_EQ(user.get_username(), weird_username);
}

// شمارنده منفی در سازنده
TEST(UserTest, NegativeWinLoseCounts) {
    std::vector<Gameround> grs;

    EXPECT_THROW(
        User user("a", "b", "c", -5, -3, grs),
        std::invalid_argument
    );
    
}

// استرس تست رکورد بازی زیاد
TEST(UserTest, MassiveGameRecordStressTest) {
    std::vector<Gameround> grs(100000, Gameround{ true, false });
    User user("mega", "tester", "stress", 50, 50, grs);
    EXPECT_EQ(user.get_gameRecord().size(), 100000);
}

// ترتیب رکوردها
TEST(UserTest, GameRecordOrderPreserved) {
    User user("x", "y", "z");

    Gameround g1{ true, false };
    Gameround g2{ false, true };
    user.add_gameRecord(g1);
    user.add_gameRecord(g2);

    auto records = user.get_gameRecord();
    EXPECT_EQ(records[0].is_CT, true);
    EXPECT_EQ(records[1].is_CT, false);
}

// خروجی JSON مینیمال
TEST(UserTest, MinimalJsonOutput) {
    User user("", "", "");
    auto j = user.to_json();
    EXPECT_EQ(j["Username"], "");
    EXPECT_EQ(j["nickname"], "");
    EXPECT_TRUE(j["game"].is_array());
    EXPECT_EQ(j["game"].size(), 0);
}

// بررسی هش تکراری برای پسورد تکراری
TEST(UserTest, PasswordHashCollision) {
    auto h1 = User::Hash_SHA_password("123456");
    auto h2 = User::Hash_SHA_password("123456");
    EXPECT_EQ(h1, h2);
}
