class Solution
{
public:
  // https://leetcode.com/problems/maximum-energy-boost-from-two-drinks/description/
  vector<vector<long long>> dp;
  long long solve(int i, vector<int> &a, vector<int> &b, int last)
  {
    if (i == a.size())
      return 0;

    if (dp[last][i] != -1)
      return dp[last][i];

    long long ans = -1e9;
    if (last == 2 || last == 0)
    {
      ans = a[i] + solve(i + 1, a, b, 0);
    }
    if (last == 2 || last == 1)
    {
      ans = max(ans, b[i] + solve(i + 1, a, b, 1));
    }

    ans = max(ans, solve(i + 1, a, b, last == 0 ? 1 : 0));

    return dp[last][i] = ans;
  }
  long long maxEnergyBoost(vector<int> &a, vector<int> &b)
  {
    dp = vector<vector<long long>>(3, vector<long long>(a.size(), -1));
    return solve(0, a, b, 2);
  }
};