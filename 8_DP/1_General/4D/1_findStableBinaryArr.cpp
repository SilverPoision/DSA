/*
Usually we ignore constant when talking about complexity. The fact is:
every operation has different costs, and memory allocation by OS is
expensive. If you are using dp[200][200][200][2], you have to request
allocation for 200^3 times, but only 200^2*2 times for dp[200][200][2][200].

vector<vector<vector<vector<int>>>> dp(zero+1, vector<vector<vector<int>>>(one+1, vector<vector<int>>(limit+1, vector<int>(3, -1)))); //this does not work because of the above reason
always init dp with smaller > large > larger
*/
class Solution
{
public:
  // https://leetcode.com/problems/find-all-possible-stable-binary-arrays-i/
  int mod = 1e9 + 7;

  int solve(int z, int o, int l, int s, int prev, vector<vector<vector<vector<int>>>> &dp)
  {
    if (z == 0 && o == 0)
    {
      return 1;
    }

    if (dp[z][o][prev][s] != -1)
      return dp[z][o][prev][s];

    if (l == s)
    {
      if (prev == 1)
      {
        if (z > 0)
        {
          return solve(z - 1, o, l, 1, 0, dp);
        }
        else
          return 0;
      }
      else
      {
        if (o > 0)
        {
          return solve(z, o - 1, l, 1, 1, dp);
        }
        else
          return 0;
      }
    }

    int zs = 0, os = 0;
    if (z > 0)
    {
      zs = solve(z - 1, o, l, prev == 0 ? s + 1 : 1, 0, dp) % mod;
    }
    if (o > 0)
    {
      os = solve(z, o - 1, l, prev == 1 ? s + 1 : 1, 1, dp) % mod;
    }

    return dp[z][o][prev][s] = (zs + os) % mod;
  }
  int numberOfStableArrays(int zero, int one, int limit)
  {
    vector<vector<vector<vector<int>>>> dp(zero + 1, vector<vector<vector<int>>>(one + 1, vector<vector<int>>(3, vector<int>(limit + 1, -1))));
    return solve(zero, one, limit, 0, 2, dp) % mod;
  }
};

//
class Solution
{
public:
  int mod = 1e9 + 7;

  int solve(int z, int o, int l, int prev, vector<vector<vector<int>>> &dp)
  {
    if (z == 0 && o == 0)
    {
      return 1;
    }

    if (dp[prev][o][z] != -1)
      return dp[prev][o][z];

    long long ans = 0;

    if (prev != 0)
    {
      for (int cnt = 1; cnt <= min(z, l); cnt++)
      {
        ans = (solve(z - cnt, o, l, 0, dp) + ans) % mod;
      }
    }
    if (prev != 1)
    {
      for (int cnt = 1; cnt <= min(o, l); cnt++)
      {
        ans = (solve(z, o - cnt, l, 1, dp) + ans) % mod;
      }
    }

    return dp[prev][o][z] = ans % mod;
  }
  int numberOfStableArrays(int zero, int one, int limit)
  {
    vector<vector<vector<int>>> dp(
        3, vector<vector<int>>(one + 1, vector<int>(zero + 1, -1)));
    return solve(zero, one, limit, 2, dp) % mod;
  }
};