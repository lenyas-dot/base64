#include "gtest/gtest.h"
#include "Functions.h"

TEST(func, t1)
{
    string a = "Man i like you";
    string result = coding(a);
    EXPECT_TRUE(result == "TWFuIGkgbGlrZSB5b3U=");
}

TEST(Decode, t2)
{
    string a = DecodeBase64("SGV5");
    EXPECT_EQ(a, "Hey");
}

TEST(Decode, t3)
{
    string a = DecodeBase64("SSBhbSBib3Nz");
    EXPECT_EQ(a, "I am boss");
}

TEST(func, t4)
{
    string a = coding("I dont like base64");
    EXPECT_EQ(a, "SSBkb250IGxpa2UgYmFzZTY0");
}





int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
