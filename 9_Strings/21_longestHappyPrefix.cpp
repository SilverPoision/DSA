class Solution
{
public:
  void getTabel(string s, vector<int> &lps)
  {
    int i = 1;
    int prevLps = 0;

    while (i < s.size())
    {
      if (s[i] == s[prevLps])
      {
        lps[i] = prevLps + 1;
        prevLps++;
        i++;
      }
      else if (prevLps == 0)
      {
        lps[i] = 0;
        i++;
      }
      else
      {
        prevLps = lps[prevLps - 1];
      }
    }
  }
  string longestPrefix(string s)
  {
    vector<int> lps(s.size(), 0);
    getTabel(s, lps);

    return s.substr(0, lps[lps.size() - 1]);
  }
};