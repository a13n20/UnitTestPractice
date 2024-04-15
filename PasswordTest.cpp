/**
 * Unit Tests for Password class
**/

#include <gtest/gtest.h>
#include "Password.h"

class PracticeTest : public ::testing::Test
{
	protected:
		PracticeTest(){} //constructor runs before each test
		virtual ~PracticeTest(){} //destructor cleans up after tests
		virtual void SetUp(){} //sets up before each test (after constructor)
		virtual void TearDown(){} //clean up after each test, (before destructor)
};

TEST(PasswordTest, single_letter_password)
{
	Password my_password;
	int actual = my_password.count_leading_characters("Z");
	ASSERT_EQ(1, actual);
}

TEST(PasswordTest, two_letter_password)
{
	Password my_password;
	int actual = my_password.count_leading_characters("ZZ");
	ASSERT_EQ(2, actual);
}

TEST(PasswordTest, letter_rand_letter_password)
{
	Password my_password;
	int actual = my_password.count_leading_characters("ZaZ");
	ASSERT_EQ(1, actual);
}

TEST(PasswordTest, rand_letter_letter_password)
{
	Password my_password;
	int actual = my_password.count_leading_characters("aZZ");
	ASSERT_EQ(1, actual);
}

TEST(PasswordText, rand_rand_rand_rand_password)
{
	Password my_password;
    int actual = my_password.count_leading_characters("abcd");
	ASSERT_EQ(1, actual);
}

TEST(PasswordText, lowercase_capital_password)
{
	Password my_password;
    int actual = my_password.count_leading_characters("zZ");
	ASSERT_EQ(1, actual);
}

TEST(PasswordText, space_space_rand_rand_password)
{
	Password my_password;
    int actual = my_password.count_leading_characters("  ab");
	ASSERT_EQ(2, actual);
}

TEST(PasswordText, special_special_rand_rand_password)
{
	Password my_password;
    int actual = my_password.count_leading_characters("!!ad");
	ASSERT_EQ(2, actual);
}

TEST(PasswordText, sql_injection_password)
{
	Password my_password;
    int actual = my_password.count_leading_characters(" ' OR '1=1");
	ASSERT_EQ(1, actual);
}

TEST(PasswordText, emoji_emoji_password)
{
	Password my_password;
    int actual = my_password.count_leading_characters("🌘🌘");
	ASSERT_EQ(0, actual);
}

TEST(PasswordText, bee_movie_password)
{
	Password my_password;
    int actual = my_password.count_leading_characters("According to all known laws of aviation, a bee is not meant to fly");
	ASSERT_EQ(1, actual);
}

TEST(PasswordText, backslash_password)
{
	Password my_password;
    int actual = my_password.count_leading_characters("\\\\\\\\\\");
	ASSERT_EQ(10, actual);
}

TEST(PasswordText, empty_password)
{
	Password my_password;
    int actual = my_password.count_leading_characters("");
	ASSERT_EQ(0, actual);
}

TEST(PasswordText, lorem_password)
{
	Password my_password;
    int actual = my_password.count_leading_characters("Lorem Ipsum");
	ASSERT_EQ(1, actual);
}

TEST(PasswordText, password_password)
{
	Password my_password;
    int actual = my_password.count_leading_characters("password");
	ASSERT_EQ(1, actual);
}

TEST(PasswordText, numbers_password)
{
	Password my_password;
    int actual = my_password.count_leading_characters("33342153");
	ASSERT_EQ(3, actual);
}