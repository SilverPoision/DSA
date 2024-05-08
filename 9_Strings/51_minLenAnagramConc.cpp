class Solution
{
public:
  // https://leetcode.com/problems/minimum-length-of-anagram-concatenation/description/
  bool checkAna(string &s, int sz)
  {
    int n = s.size();
    vector<int> hash(26, 0);

    for (int i = 0; i < sz; i++)
    {
      hash[s[i] - 'a']++;
    }

    for (int i = sz; i < n; i += sz)
    {
      vector<int> h(26, 0);
      for (int k = i; k < i + sz; k++)
      {
        h[s[k] - 'a']++;
      }

      for (int k = 0; k < 26; k++)
      {
        if (h[k] != hash[k])
          return false;
      }
    }

    return true;
  }
  int minAnagramLength(string s)
  {
    for (int low = 1; low < s.size(); low++)
    {
      if ((s.size() % low) == 0 && checkAna(s, low))
        return low;
    }

    return s.size();
  }
};