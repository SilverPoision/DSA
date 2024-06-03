class Solution
{
public:
  // https://leetcode.com/problems/append-characters-to-string-to-make-subsequence/
  int appendCharacters(string s, string t)
  {
    int n = s.size();
    int m = t.size();

    int i = 0, j = 0;

    while (i < n && j < m)
    {
      if (s[i] == t[j])
      {
        j++;
      }
      i++;
    }

    if (j == m)
      return 0;

    return m - j;
  }
};