#include <gtest/gtest.h>
#include "../main classes/CT_class/CT_Class.h"


//test baksh player joda neveshte shode

TEST(CTTest, ConstructorWithValidParameters) {
    CT ct("John", 100, 50, 2000, false, true, false);

    EXPECT_EQ(ct.get_name(), "John");
    EXPECT_EQ(ct.get_health(), 100);
    EXPECT_TRUE(ct.haveKit());
    EXPECT_FALSE(ct.defusingBomb());
}

TEST(CTTest, DefaultConstructor) {
    CT ct;

    EXPECT_EQ(ct.get_name(), "unknown");
    EXPECT_EQ(ct.get_health(), 1);
    EXPECT_FALSE(ct.haveKit()); 
    EXPECT_FALSE(ct.defusingBomb());
}

//edge
TEST(CTTest, ZeroValuesInConstructor) {
    CT ct("ZeroCT", 0, 0, 0, true, false, true);

    EXPECT_EQ(ct.get_health(), 0);
    EXPECT_FALSE(ct.is_Alive());
    EXPECT_TRUE(ct.defusingBomb());
}

TEST(CTTest, ToggleKitAndDefuseStatus) {
    CT ct("Agent", 80, 30, 1000, false, false, false);
    ct.giveAKit(true);
    ct.heDefusingTheBomb(true);

    EXPECT_TRUE(ct.haveKit());
    EXPECT_TRUE(ct.defusingBomb());
}

//Error
TEST(CTTest, AddAndRemoveFromMap) {
    auto ct = std::make_shared<CT>("CT1", 100, 20, 500, false, true, false);
    string ctGuid = CT::add_tomap(ct);

    EXPECT_TRUE(CT::isValidCT(ctGuid));
    EXPECT_EQ(CT::get_CT_count(), 1);

    CT::delete_from_map(ctGuid);
    EXPECT_FALSE(CT::isValidCT(ctGuid));
}

TEST(CTTest, RetrieveNonExistentCT) {
    std::string invalidGuid = "invalid_123";
    auto ct = CT::get_from_map(invalidGuid);

    EXPECT_EQ(ct, nullptr);
}
