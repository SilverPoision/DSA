// Most Optimal through BS
class Solution
{
public:
  // https://leetcode.com/problems/russian-doll-envelopes/
  static bool comp(vector<int> a, vector<int> b)
  {
    if (a[0] == b[0])
    {
      return b[1] < a[1];
    }
    return a[0] < b[0];
  }
  int maxEnvelopes(vector<vector<int>> &env)
  {
    int n = env.size();
    if (n == 0)
      return 0;

    sort(env.begin(), env.end(), comp); // sorting the env[0] inc and env[1] dec to take the smaller one first
    vector<int> dp;
    dp.push_back(env[0][1]);

    for (int i = 1; i < n; i++)
    {
      int ind = lower_bound(dp.begin(), dp.end(), env[i][1]) - dp.begin();
      if (ind == dp.size())
      {
        dp.push_back(env[i][1]);
      }
      else
      {
        dp[ind] = env[i][1];
      }
    }

    return dp.size();
  }
};

// DP
class Solution
{
public:
  int f(int i, vector<vector<int>> &env, int n)
  {
    if (i == n)
    {
      return 0;
    }

    int maxi = 0;
    for (int k = i + 1; k < n; k++)
    {
      if (env[k][0] > env[i][0] && env[k][1] > env[i][1])
      {
        maxi = max(maxi, 1 + f(k, env, n));
      }
    }

    return maxi;
  }
  int maxEnvelopes(vector<vector<int>> &env)
  {
    sort(env.begin(), env.end());
    int maxi = 0;
    for (int i = 0; i < env.size(); i++)
    {
      maxi = max(maxi, f(i, env, env.size()) + 1);
    }

    return maxi;
  }
};

// Memo
class Solution
{
public:
  int f(int i, vector<vector<int>> &env, int n, vector<int> &dp)
  {
    if (i == n)
    {
      return 0;
    }

    if (dp[i] != -1)
      return dp[i];

    int maxi = 0;
    for (int k = i + 1; k < n; k++)
    {
      if (env[k][0] > env[i][0] && env[k][1] > env[i][1])
      {
        maxi = max(maxi, 1 + f(k, env, n, dp));
      }
    }

    return dp[i] = maxi;
  }
  int maxEnvelopes(vector<vector<int>> &env)
  {
    int n = env.size();
    sort(env.begin(), env.end());
    vector<int> dp(n, -1);

    int maxi = 0;
    for (int i = 0; i < n; i++)
    {
      maxi = max(maxi, f(i, env, n, dp) + 1);
    }

    return maxi;
  }
};

// tab
int maxEnvelopes(vector<vector<int>> &env)
{
  int n = env.size();
  if (n == 0)
    return 0;

  sort(env.begin(), env.end());
  vector<int> dp(n, 1);

  int maxi = 0;
  for (int i = n - 2; i >= 0; i--)
  {
    for (int k = i + 1; k < n; k++)
    {
      if (env[k][0] > env[i][0] && env[k][1] > env[i][1] && dp[i] < dp[k] + 1)
      {
        dp[i] = 1 + dp[k];
      }
    }
    maxi = max(maxi, dp[i]);
  }

  return maxi;
}