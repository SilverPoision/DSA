class Solution
{
public:
  int solve(int i, string s, vector<int> &dp)
  {
    if (i == s.size())
      return 1;

    if (dp[i] != -1)
      return dp[i];

    int ans = 0;

    int oneDigi = s[i] - '0';
    int twoDigi = stoi(s.substr(i, 2));

    if (oneDigi > 0)
    {
      ans += solve(i + 1, s, dp);
    }
    if (twoDigi >= 10 && twoDigi <= 26)
    {
      ans += solve(i + 2, s, dp);
    }

    return dp[i] = ans;
  }

  int numDecodings(string s)
  {
    vector<int> dp(101, -1);

    return solve(0, s, dp);
  }
};

// tab
class Solution
{
public:
  int numDecodings(string s)
  {
    int n = s.size();
    if (n == 0 || s[0] == '0')
      return 0;

    vector<int> dp(n + 2, 0);
    dp[0] = 1;
    dp[1] = 1;

    for (int i = 2; i <= n; i++)
    {
      int ans = 0;

      int oneDigi = s[i - 1] - '0';
      int twoDigi = stoi(s.substr(i - 2, 2));

      if (oneDigi != 0)
      {
        ans += dp[i - 1];
      }
      if (twoDigi >= 10 && twoDigi <= 26)
      {
        ans += dp[i - 2];
      }

      dp[i] = ans;
    }

    return dp[n];
  }
};

// same but not efficient
class Solution
{
public:
  int solve(int i, string s, unordered_map<string, char> &hash, vector<int> &dp)
  {
    if (i == s.size())
      return 1;

    if (dp[i] != -1)
      return dp[i];

    int ans = 0;

    if (hash.find(s.substr(i, 1)) != hash.end())
    {
      ans += solve(i + 1, s, hash, dp);
    }
    if (i + 1 < s.size() && hash.find(s.substr(i, 2)) != hash.end())
    {
      ans += solve(i + 2, s, hash, dp);
    }

    return dp[i] = ans;
  }

  int numDecodings(string s)
  {
    unordered_map<string, char> hash;
    int i = 1;
    for (char ch = 'A'; ch <= 'Z'; ch++)
    {
      hash[to_string(i)] = ch;
      i++;
    }

    vector<int> dp(101, -1);

    return solve(0, s, hash, dp);
  }
};

// same
class Solution
{
public:
  int solve(string s, unordered_map<string, char> &hash, unordered_map<string, int> &dp)
  {
    if (s.size() == 0)
      return 1;

    if (dp.find(s) != dp.end())
      return dp[s];

    int ans = 0;

    if (hash.find(s.substr(0, 1)) != hash.end())
    {
      ans += solve(s.substr(1), hash, dp);
    }
    if (s.size() > 1 && hash.find(s.substr(0, 2)) != hash.end())
    {
      ans += solve(s.substr(2), hash, dp);
    }

    return dp[s] = ans;
  }

  int numDecodings(string s)
  {
    unordered_map<string, char> hash;
    unordered_map<string, int> dp;
    int i = 1;
    for (char ch = 'A'; ch <= 'Z'; ch++)
    {
      hash[to_string(i)] = ch;
      i++;
    }

    return solve(s, hash, dp);
  }
};