class Solution
{
public:
  // https://leetcode.com/problems/find-the-count-of-monotonic-pairs-i/
  int dp[2001][52][52];
  int mod = 1e9 + 7;
  int n;
  int solve(int i, vector<int> &nums, int prev1, int prev2)
  {
    if (i == n)
      return 1;

    if (dp[i][prev1][prev2] != -1)
      return dp[i][prev1][prev2];

    int ans = 0;
    for (int k = prev1; k <= nums[i]; k++)
    {
      int x1 = k;
      int x2 = nums[i] - x1;

      if (x1 >= prev1 && x2 <= prev2)
      {
        ans = (ans + solve(i + 1, nums, x1, x2)) % mod;
      }
    }

    return dp[i][prev1][prev2] = ans;
  }
  int countOfPairs(vector<int> &nums)
  {
    this->n = nums.size();
    memset(dp, -1, sizeof(dp));
    return solve(0, nums, 0, 50);
  }
};