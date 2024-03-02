class Solution
{
public:
  bool f(int i, int j, string &s1, string &s2, string &s3, vector<vector<int>> &dp)
  {
    if (i + j == s3.size())
      return true;

    if (dp[i][j] != -1)
      return dp[i][j];

    bool take1 = false, take2 = false;

    if (s1[i] == s3[i + j] && i < s1.size())
    {
      take1 = f(i + 1, j, s1, s2, s3, dp);
    }
    if (s2[j] == s3[i + j] && j < s2.size())
    {
      take2 = f(i, j + 1, s1, s2, s3, dp);
    }

    return dp[i][j] = take1 || take2;
  }

  bool isInterleave(string s1, string s2, string s3)
  {
    if (s1.size() + s2.size() != s3.size())
      return false;
    vector<vector<int>> dp(s1.size() + 1, vector<int>(s2.size() + 1, -1));
    return f(0, 0, s1, s2, s3, dp);
  }
};

// tab
class Solution
{
public:
  bool isInterleave(string s1, string s2, string s3)
  {
    if (s1.size() + s2.size() != s3.size())
      return false;
    vector<vector<bool>> dp(s1.size() + 1, vector<bool>(s2.size() + 1, false));

    dp[s1.size()][s2.size()] = true;

    for (int i = s1.size(); i >= 0; i--)
    {
      for (int j = s2.size(); j >= 0; j--)
      {
        if (i < s1.size() && s1[i] == s3[i + j] && dp[i + 1][j])
        {
          dp[i][j] = true;
        }
        if (j < s2.size() && s2[j] == s3[i + j] && dp[i][j + 1])
        {
          dp[i][j] = true;
        }
      }
    }

    return dp[0][0];
  }
};