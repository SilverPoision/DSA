class Solution
{
public:
  // https://www.geeksforgeeks.org/problems/sum-of-all-substrings-of-a-number-1587115621/1
  // Function to find sum of all possible substrings of the given string.
  long long sumSubstrings(string s)
  {

    // your code here
    string t = s;
    int mod = 1e9 + 7;

    while (t[0] == '0')
    {
      t = t.substr(1);
    }

    long long cur = t[0] - '0';
    long long sum = t[0] - '0';

    for (int i = 1; i < t.size(); i++)
    {
      cur = ((cur * 10) % mod + ((i + 1) * (t[i] - '0')) % mod) % mod;
      sum = (sum + cur) % mod;
    }

    return sum % mod;
  }
};