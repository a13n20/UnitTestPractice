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

////// count_leading_characters tests //////
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

////// has_mixed_case tests //////
TEST(PasswordText, numbers_no_case_password)
{
	Password my_password;
    int actual = my_password.has_mixed_case("33342153");
	ASSERT_EQ(false, actual);
}

TEST(PasswordText, mixed_case_password)
{
	Password my_password;
    int actual = my_password.has_mixed_case("zA");
	ASSERT_EQ(true, actual);
}

TEST(PasswordText, multiple_mixed_cases_password)
{
	Password my_password;
    int actual = my_password.has_mixed_case("bakDgAjefVa");
	ASSERT_EQ(true, actual);
}

TEST(PasswordText, all_lower_password)
{
	Password my_password;
    int actual = my_password.has_mixed_case("akosfbefboefo");
	ASSERT_EQ(false, actual);
}

TEST(PasswordText, all_upper_password)
{
	Password my_password;
    int actual = my_password.has_mixed_case("HOIDGOSDGJJSD");
	ASSERT_EQ(false, actual);
}

TEST(PasswordText, no_characters_password)
{
	Password my_password;
    int actual = my_password.has_mixed_case("");
	ASSERT_EQ(false, actual);
}

TEST(PasswordText, all_spaces_password)
{
	Password my_password;
    int actual = my_password.has_mixed_case("         ");
	ASSERT_EQ(false, actual);
}

TEST(PasswordText, lower_space_upper_password)
{
	Password my_password;
    int actual = my_password.has_mixed_case("a               A");
	ASSERT_EQ(true, actual);
}

TEST(PasswordText, special_and_valid_password)
{
	Password my_password;
    int actual = my_password.has_mixed_case("fhAvienGvh@^sjc$5Ajivd");
	ASSERT_EQ(true, actual);
}

TEST(PasswordText, percent_password)
{
	Password my_password;
    int actual = my_password.has_mixed_case("lafbjc%A");
	ASSERT_EQ(true, actual);
}

////// set password test //////
TEST(PasswordText, constuctor_test)
{
	Password my_password;
	bool actual = my_password.authenticate("ChicoCA-95929");
	ASSERT_EQ(true, actual);
}

TEST(PasswordText, set_empty_test)
{
	Password my_password;
	my_password.set("");
	bool actual = my_password.authenticate("");
	ASSERT_EQ(false, actual);
}

TEST(PasswordText, set_bad_test)
{
	Password my_password;
	my_password.set("bad");
	bool actual = my_password.authenticate("bad");
	ASSERT_EQ(false, actual);
}

TEST(PasswordText, set_good_test)
{
	Password my_password;
	my_password.set("tHispAsswordWorks");
	bool actual = my_password.authenticate("tHispAsswordWorks");
	ASSERT_EQ(true, actual);
}

TEST(PasswordText, bad_mix_case_test)
{
	Password my_password;
	my_password.set("passwordwontwork");
	bool actual = my_password.authenticate("passwordwontwork");
	ASSERT_EQ(false, actual);
}

TEST(PasswordText, bad_length_test)
{
	Password my_password;
	my_password.set("no");
	bool actual = my_password.authenticate("no");
	ASSERT_EQ(false, actual);
}

TEST(PasswordTest, valid_passowrd_specials)
{
	Password my_password;
	my_password.set("v@lIdpW0rd");
	bool actual = my_password.authenticate("v@lIdpW0rd");
	ASSERT_EQ(true, actual);
}

TEST(PasswordTest, invalid_morethan3_password)
{
	Password my_password;
	my_password.set("iiiinvalid");
	bool actual = my_password.authenticate("iiiinvalid");
	ASSERT_EQ(false, actual);
}

TEST(PasswordTest, valid_exactly3_password)
{
	Password my_password;
	my_password.set("vvvalidPword");
	bool actual = my_password.authenticate("vvvalidPword");
	ASSERT_EQ(true, actual);
}

TEST(PasswordTest, invalid_morethan20_password)
{
	Password my_password;
	my_password.set("dnlknfHihoanfsjkansofnonacNJNFononnonso");
	bool actual = my_password.authenticate("dnlknfHihoanfsjkansofnonacNJNFononnonso");
	ASSERT_EQ(false, actual);
}

TEST(PasswordTest, spaces_valid_password)
{
	Password my_password;
	my_password.set("   ValId    ");
	bool actual = my_password.authenticate("   ValId    ");
	ASSERT_EQ(true, actual);
}

TEST(PasswordTest, 3backslash_password)
{
	Password my_password;
	my_password.set("///isValid");
	bool actual = my_password.authenticate("///isValid");
	ASSERT_EQ(true, actual);
}

TEST(PasswordTest, 6backslash_password)
{
	Password my_password;
	my_password.set("//////notValidx");
	bool actual = my_password.authenticate("//////notValidx");
	ASSERT_EQ(false, actual);
}

TEST(PasswordTest, set_multiple_previous_password)
{
	Password my_password;
	my_password.set("thisPassisValid");
	my_password.set("antHerValid");
	my_password.set("ValidpassWord");
	bool actual = my_password.authenticate("thisPassisValid");
	ASSERT_EQ(false, actual);
}

TEST(PasswordTest, set_multiple_new_password)
{
	Password my_password;
	my_password.set("thisPassisValid");
	my_password.set("antHerValid");
	my_password.set("ValidpassWord");
	bool actual = my_password.authenticate("ValidpassWord");
	ASSERT_EQ(true, actual);
}

TEST(PasswordTest, set_old_password_password)
{
	Password my_password;
	my_password.set("thisPassisValid");
	my_password.set("antHerValid");
	my_password.set("thisPassisValid");
	bool actual = my_password.authenticate("antHerValid");
	ASSERT_EQ(true, actual);
}

TEST(PasswordTest, set_very_old_password_password)
{
	Password my_password;
	my_password.set("thisPassisValid");
	my_password.set("nEwPassword");
	my_password.set("anEvenNewerpWord");
	my_password.set("omgAnother1");
	my_password.set("antHerValid");
	my_password.set("thisPassisValid");
	bool actual = my_password.authenticate("antHerValid");
	ASSERT_EQ(true, actual);
}

TEST(PasswordTest, set_relatively_old_password_password)
{
	Password my_password;
	my_password.set("thisPassisValid");
	my_password.set("nEwPassword");
	my_password.set("anEvenNewerpWord");
	my_password.set("omgAnother1");
	my_password.set("antHerValid");
	my_password.set("anEvenNewerpWord");
	bool actual = my_password.authenticate("antHerValid");
	ASSERT_EQ(true, actual);
}