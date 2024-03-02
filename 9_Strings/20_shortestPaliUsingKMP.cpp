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
  string shortestPalindrome(string s)
  {
    string rev = s;
    reverse(rev.begin(), rev.end());
    string temp = s + "#" + rev;
    vector<int> lps(temp.size(), 0);
    getTabel(temp, lps);

    string a = s.substr(lps[lps.size() - 1]);
    reverse(a.begin(), a.end());

    return a + s;
  }
};