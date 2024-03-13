class Solution
{
public:
  // https://leetcode.com/problems/minimum-length-of-string-after-deleting-similar-ends/
  int minimumLength(string s)
  {
    int n = s.size();

    int i = 0, j = n - 1;

    while (i < j)
    {
      if (s[i] != s[j])
        return j - i + 1;
      while (i < n - 1 && i < j - 1 && s[i + 1] == s[i])
        i++;
      while (j > 0 && j > i + 1 && s[j] == s[j - 1])
        j--;

      i++;
      j--;
    }

    return j - i + 1;
  }
};