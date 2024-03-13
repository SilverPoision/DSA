class Solution
{
public:
  // try the tabulation method
  //  https://leetcode.com/problems/maximum-strength-of-k-disjoint-subarrays/description/
  typedef long long ll;
  int n;
  vector<vector<vector<ll>>> dp;
  ll solve(int i, vector<int> &nums, ll k, bool startNew)
  {
    if (k == 0)
      return 0;

    if (i >= n)
    {
      return -1e18;
    }

    if (dp[i][k][startNew] != -1)
      return dp[i][k][startNew];

    ll not_take = -1e18;
    ll take = -1e18;

    if (startNew)
    {
      not_take = solve(i + 1, nums, k, startNew);
    }

    if (k % 2 != 0)
    {
      take = solve(i + 1, nums, k - 1, true) + nums[i] * k;
      take = max(take, solve(i + 1, nums, k, false) + nums[i] * k);
    }
    else
    {
      take = solve(i + 1, nums, k - 1, true) - nums[i] * k;
      take = max(take, solve(i + 1, nums, k, false) - nums[i] * k);
    }

    return dp[i][k][startNew] = max(take, not_take);
  }
  long long maximumStrength(vector<int> &nums, int k)
  {
    n = nums.size();
    dp.resize(n + 1, vector<vector<ll>>(k + 1, vector<ll>(2, -1)));
    bool startNew = true;
    return solve(0, nums, k, startNew);
  }
};