class Solution
{
public:
  // https://leetcode.com/problems/longest-palindrome/
  int longestPalindrome(string s)
  {
    vector<int> hash(65, 0);

    for (auto it : s)
    {
      hash[it - 'A']++;
    }

    int even = 0;
    bool odd = false;
    for (auto it : hash)
    {
      if (it % 2 == 1)
      {
        even += it - 1;
        odd = true;
      }
      else
        even += it;
    }

    return even + odd;
  }
};