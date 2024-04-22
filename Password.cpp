#include "Password.h"
#include <string>

using std::string;

/*
constructor sets the default password to "ChicoCA-95929"
*/
Password::Password()
{
  pass_history.push_back("ChicoCA-95929");
}

/*
  The function receives a string counts how many times the same character
  occurs at the beginning of the string, before any other characters (or the
  end of the string). The function is case-sensitive so 'Z' is different than
  'z' and any ASCII characters are allowed.
*/
int Password::count_leading_characters(string phrase)
{
  int repetition = 1;
  int index = 0;
  if (phrase.length() == 0)
  {
    return 0;
  }
  while (index < phrase.length() && phrase[index] == phrase[index + 1])
  {
    repetition++;
    index++;
  }
  return repetition;
}

bool Password::has_mixed_case(string phrase)
{
  bool lower = false;
  bool upper = false;
  int index = 0;

  while (index < phrase.length())
  {
    if (isupper(phrase[index]))
    {
      upper = true;
    }
    if (islower(phrase[index]))
    {
      lower = true;
    }
    index++;
  }

  return (lower && upper);
}

/*
receives a password and sets the latest in pass_history to it if and only
if it meets all criteria:
  1. The password is at least 8 letters long, but no longer than 20
  2. It has no more than 3 of the same leading characters
  3. It has mixed case (at least one upper case and at least one lower case)
  4. It was not a previous password in the history
*/
void Password::set(string newPass)
{
  if (newPass.length() >= 8 && newPass.length() <= 20)
  {
    if (count_leading_characters(newPass) <= 3 && has_mixed_case(newPass) == true)
    {
      for (int i = 0; i < pass_history.size(); ++i)
      {
        if (pass_history[i] == newPass)
        {
          return;
        }
      }
      pass_history.push_back(newPass);
    }
  }
}

/*
receives a string and authenticates it against the latest password in the
pass_history, returning true for an exact match or false when it does not match
or if a password has not been set.
*/
bool Password::authenticate(string phrase)
{
  if (phrase == pass_history[pass_history.size() - 1])
  {
    return true;
  }
  else
  {
    return false;
  }
}
