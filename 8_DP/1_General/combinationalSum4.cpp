class Solution
{
public:
  int helper(vector<int> &nums, int target, vector<int> &dp, int ans)
  {
    if (target == 0)
    {
      return 1;
    }
    if (target < 0)
      return 0;

    if (dp[target] != -1)
    {
      return dp[target];
    }

    int cnt = 0;
    for (int i = 0; i < nums.size(); i++)
    {
      cnt += helper(nums, target - nums[i], dp, ans);
    }
    ans += cnt;
    dp[target] = ans;
    return ans;
  }
  int combinationSum4(vector<int> &nums, int target)
  {
    vector<int> dp(target + 1, -1);
    return helper(nums, target, dp, 0);
  }
};