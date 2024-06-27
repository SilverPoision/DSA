class Solution
{
public:
  // https://leetcode.com/problems/maximize-total-cost-of-alternating-subarrays/
  vector<vector<long long>> dp;
  long long solve(int i, vector<int> &nums, int last)
  {
    if (i == nums.size())
    {
      return 0;
    }

    if (dp[i][last] != -1)
      return dp[i][last];

    long long take = (last == 1 ? -1 * nums[i] : nums[i]) + solve(i + 1, nums, last == 0 ? 1 : 0);
    long long notTake = nums[i] + solve(i + 1, nums, 1);

    return dp[i][last] = max(take, notTake);
  }
  long long maximumTotalCost(vector<int> &nums)
  {
    dp = vector<vector<long long>>(nums.size(), vector<long long>(2, -1));
    return solve(0, nums, 0);
  }
};

// tab
class Solution
{
public:
  long long maximumTotalCost(vector<int> &nums)
  {
    int n = nums.size();
    vector<vector<long long>> dp(n + 1, vector<long long>(2, 0));

    for (int i = n - 1; i >= 0; i--)
    {
      for (int last = 1; last >= 0; last--)
      {
        long long take = (last == 1 ? -1 * nums[i] : nums[i]) + dp[i + 1][last == 0 ? 1 : 0];
        long long notTake = nums[i] + dp[i + 1][1];

        dp[i][last] = max(take, notTake);
      }
    }

    return dp[0][0];
  }
};

// SO
class Solution
{
public:
  long long maximumTotalCost(vector<int> &nums)
  {
    int n = nums.size();
    vector<long long> curr(2, 0), prev(2, 0);

    for (int i = n - 1; i >= 0; i--)
    {
      for (int last = 1; last >= 0; last--)
      {
        long long take = (last == 1 ? -1 * nums[i] : nums[i]) + prev[last == 0 ? 1 : 0];
        long long notTake = nums[i] + prev[1];

        curr[last] = max(take, notTake);
      }
      prev = curr;
    }

    return prev[0];
  }
};