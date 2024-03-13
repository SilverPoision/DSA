class Solution
{
public:
  // https://www.geeksforgeeks.org/problems/longest-repeating-and-non-overlapping-substring3421/1
  bool find(string s, string str)
  {
    int n = s.size(), m = str.size();

    for (int i = 0; i <= n - m; i++)
    {
      if (s.substr(i, m) == str)
        return true;
    }

    return false;
  }
  string longestSubstring(string s, int n)
  {
    // code here
    int i = 0, j = 0;
    string ans = "-1";
    int maxLen = 0;

    while (i < n && j < n)
    {
      string str = s.substr(i, j - i + 1);

      if (find(s.substr(j + 1), str))
      {
        int len = str.size();

        if (len > maxLen)
        {
          maxLen = len;
          ans = str;
        }
      }
      else
      {
        i++;
      }
      j++;
    }

    return ans;
  }
};