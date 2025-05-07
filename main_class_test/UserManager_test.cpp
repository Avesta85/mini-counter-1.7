#include <gtest/gtest.h>
#include "../main classes/UserManager/UserManager.h"
#include "../main classes/User/User.h"
#include <memory>
#include <filesystem>

class UserManagerTest : public ::testing::Test {
protected:
    void SetUp() override {
        // هر تست در حالت تست اجرا می‌شود
        UserManager::set_test_mode(true);
    }

    void TearDown() override {
        // پاک کردن فایل تست بعد از هر تست
        if (std::filesystem::exists("data/test_users.json")) {
            std::filesystem::remove("data/test_users.json");
        }
    }
};

// تست‌های پایه - بررسی عملکرد اصلی و معمولی کلاس
TEST_F(UserManagerTest, BasicUserRegistration) {
    auto& manager = UserManager::get_instance();
    // تست ثبت نام کاربر با اطلاعات معتبر
    User newUser("testUser", "testNick", "testPass123");
    EXPECT_TRUE(manager.User_register(newUser));
}

// تست ورود کاربر با اطلاعات صحیح
TEST_F(UserManagerTest, BasicUserLogin) {
    auto& manager = UserManager::get_instance();
    std::unique_ptr<User> userHolder;
    
    // ثبت نام کاربر جدید
    User newUser("loginUser", "loginNick", "pass123");
    EXPECT_TRUE(manager.User_register(newUser));
    
    // تلاش برای ورود
    EXPECT_TRUE(manager.user_Login("loginUser", "pass123", userHolder));
    ASSERT_NE(userHolder, nullptr);
    EXPECT_EQ(userHolder->get_username(), "loginUser");
}

// تست ذخیره و بازیابی اطلاعات از فایل
TEST_F(UserManagerTest, BasicSaveAndLoad) {
    auto& manager = UserManager::get_instance();
    
    // پاک کردن لیست کاربران قبلی
    manager.loadUserFromJson();
     
    // ثبت نام کاربر جدید
    User testUser("saveUser", "saveNick", "savePass");
    EXPECT_TRUE(manager.User_register(testUser));  
    
    // ذخیره در فایل
    manager.saveUserIntoJson();
    
    // بازیابی مجدد از فایل
    manager.loadUserFromJson();
    
    // تلاش برای ورود با همان اطلاعات
    std::unique_ptr<User> loadedUser;
    EXPECT_TRUE(manager.user_Login("saveUser", "savePass", loadedUser));
    ASSERT_NE(loadedUser, nullptr);
}

// تست‌های مرزی - بررسی شرایط حدی و غیرمعمول
// تست کاراکترهای خاص و غیرمجاز در نام کاربری
TEST_F(UserManagerTest, EdgeCaseInvalidCharacters) {
    auto& manager = UserManager::get_instance();
    User specialUser("user!@#$%^&*()", "nick", "pass123");
    EXPECT_FALSE(manager.User_register(specialUser));
}

// تست نام کاربری خیلی طولانی  
TEST_F(UserManagerTest, EdgeCaseExtremelyLongUsername) {
    auto& manager = UserManager::get_instance();
    std::string longUsername(10000, 'a');
    User longUser(longUsername, "nick", "pass123");
    EXPECT_FALSE(manager.User_register(longUser));
}

// تست‌های ایجادکننده خطا - بررسی شرایط خطا و غیرعادی
// تست ثبت نام کاربران تکراری با اطلاعات مختلف
TEST_F(UserManagerTest, ErrorCaseMultipleDuplicateUsers) {
    auto& manager = UserManager::get_instance();
    User original("dupUser", "nick1", "pass123");
    User duplicate1("dupUser", "nick2", "differentPass");
    User duplicate2("dupUser", "nick1", "pass123");
    
    EXPECT_TRUE(manager.User_register(original));
    EXPECT_FALSE(manager.User_register(duplicate1));
    EXPECT_FALSE(manager.User_register(duplicate2));
}

// تست تلاش‌های متعدد ورود ناموفق
TEST_F(UserManagerTest, ErrorCaseMultipleFailedLogins) {
    auto& manager = UserManager::get_instance();
    std::unique_ptr<User> userHolder;
    
    // ثبت نام کاربر جدید
    User validUser("failUser", "failNick", "correctPass");
    EXPECT_TRUE(manager.User_register(validUser));
    
    // تلاش‌های مختلف با رمزهای اشتباه
    EXPECT_FALSE(manager.user_Login("failUser", "wrongPass1", userHolder));
    EXPECT_FALSE(manager.user_Login("failUser", "wrongPass2", userHolder));
    EXPECT_FALSE(manager.user_Login("failUser", "wrongPass3", userHolder));
    
    // تست ورود موفق بعد از تلاش‌های ناموفق
    EXPECT_TRUE(manager.user_Login("failUser", "correctPass", userHolder));
    ASSERT_NE(userHolder, nullptr);
}

// تست فایل json خراب یا دستکاری شده
TEST_F(UserManagerTest, ErrorCaseCorruptedJsonFile) {
    auto& manager = UserManager::get_instance();
    
    // ایجاد فایل JSON نامعتبر
    std::ofstream file("data/test_users.json");
    file << "{\"users\": [{\"username\": \"test\", \"password\": \"incomplete...";
    file.close();
    
    EXPECT_NO_THROW(manager.loadUserFromJson());
}

// تست حافظه و منابع
TEST_F(UserManagerTest, ErrorCaseMemoryStress) {
    auto& manager = UserManager::get_instance();
    
    // ثبت تعدادی کاربر برای تست سریع‌تر حافظه
    for(int i = 0; i < 50; i++) {
        User user("stress_user_" + std::to_string(i),
                 "nick_" + std::to_string(i),
                 "pass123");
        manager.User_register(user);
    }
    
    // ذخیره و بازیابی کاربران
    EXPECT_NO_THROW(manager.saveUserIntoJson());
    EXPECT_NO_THROW(manager.loadUserFromJson());
} 