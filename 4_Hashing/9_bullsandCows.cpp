/*
299. Bulls and Cows
Medium
2K
1.6K
Companies
You are playing the Bulls and Cows game with your friend.

You write down a secret number and ask your friend to guess what the number is. When your friend makes a guess, you provide a hint with the following info:

The number of "bulls", which are digits in the guess that are in the correct position.
The number of "cows", which are digits in the guess that are in your secret number but are located in the wrong position. Specifically, the non-bull digits in the guess that could be rearranged such that they become bulls.
Given the secret number secret and your friend's guess guess, return the hint for your friend's guess.

The hint should be formatted as "xAyB", where x is the number of bulls and y is the number of cows. Note that both secret and guess may contain duplicate digits.



Example 1:

Input: secret = "1807", guess = "7810"
Output: "1A3B"
Explanation: Bulls are connected with a '|' and cows are underlined:
"1807"
  |
"7810"
*/

class Solution
{
public:
  string getHint(string s, string g)
  {
    vector<int> hash(10, 0); // this stores the info about the numbers that are
    // not in the guess and when we find out the count of no that are not in
    // guess then we can simply subtract the bull and count of no that are not
    // it the guess by total number to get the cows.

    int bull = 0;
    for (int i = 0; i < s.size(); i++)
    {
      if (s[i] == g[i])
        bull++;
      else
      {
        hash[int(s[i] - '0')]++;
        hash[int(g[i] - '0')]--;
      }
    }

    int sum = 0;
    for (auto it : hash)
    {
      if (it > 0)
        sum += it;
    }

    string ans = to_string(bull) + "A" + to_string(s.size() - bull - sum) + "B";
    return ans;
  }
};