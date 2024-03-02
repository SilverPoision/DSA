class Solution
{
public:
  bool isAnagram(string s, string t)
  {
    if (s.length() != t.length())
      return false;
    if (s.length() <= 1)
    {
      return s[0] == t[0];
    }

    vector<int> arr1(26, 0);
    vector<int> arr2(26, 0);
    for (int i = 0; i < s.length(); i++)
    {
      arr1[s[i] - 'a']++;
      arr2[t[i] - 'a']++;
    }

    for (int i = 0; i < 26; i++)
    {
      if (arr1[i] != arr2[i])
      {
        return false;
      }
    }

    return true;
  }
};