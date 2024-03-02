class Solution
{
public:
  bool f(int i, int n, string &s, set<string> &word, vector<int> &dp)
  {
    if (i == n)
      return true;

    if (dp[i] != -1)
      return dp[i];

    string temp;
    for (int k = i; k < n; k++)
    {
      temp += s[k];
      if (word.find(temp) != word.end())
      {
        if (f(k + 1, n, s, word, dp))
        {
          return dp[i] = true;
        }
      }
    }
    return dp[i] = false;
  }

  bool wordBreak(string s, vector<string> &wordDict)
  {
    set<string> st;
    for (auto it : wordDict)
      st.insert(it);
    vector<int> dp(s.length(), -1);
    return f(0, s.length(), s, st, dp);
  }
};

// Tab
class Solution
{
public:
  bool wordBreak(string s, vector<string> &wordDict)
  {
    set<string> st;
    int n = s.length();
    for (auto it : wordDict)
      st.insert(it);
    vector<int> dp(n + 1, false);

    dp[n] = true;
    for (int i = n - 1; i >= 0; i--)
    {
      string temp;
      for (int k = i; k < n; k++)
      {
        temp += s[k];
        if (st.find(temp) != st.end() && dp[k + 1])
        {
          dp[i] = true;
          break;
        }
      }
    }
    return dp[0];
  }
};