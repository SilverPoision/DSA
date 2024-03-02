// see why this is solved this way
// https://www.youtube.com/watch?v=b3GD8263-PQ&list=PLgUwDviBIf0qUlt5H_kiKYaNSqJ81PMMY&index=22s

class Solution
{
public:
  int f(int i, vector<int> &nums, int target, vector<vector<int>> &dp)
  {
    if (i < 0)
    {
      if (target == 0)
        return 1;
      return 0;
    }

    if (dp[i][target + 2000] != -1)
      return dp[i][target + 2000];

    int plus = f(i - 1, nums, target - nums[i], dp);
    int minus = f(i - 1, nums, target + nums[i], dp);

    return dp[i][target + 2000] = plus + minus;
  }
  int findTargetSumWays(vector<int> &nums, int target)
  {
    int n = nums.size();
    vector<vector<int>> dp(n, vector<int>(4001, -1));
    return f(n - 1, nums, target, dp);
  }
};

// tab

class Solution
{
public:
  int findWays(vector<int> &num, int tar)
  {
    int n = num.size();
    vector<vector<int>> dp(n, vector<int>(tar + 1, 0));
    if (num[0] == 0)
    {
      dp[0][0] = 2;
    }
    else
    {
      dp[0][0] = 1;
    }

    if (num[0] != 0 && num[0] <= tar)
      dp[0][num[0]] = 1;

    for (int i = 1; i < n; i++)
    {
      for (int j = 0; j <= tar; j++)
      {
        int notTake = dp[i - 1][j];
        int take = 0;
        if (num[i] <= j)
          take = dp[i - 1][j - num[i]];
        dp[i][j] = (notTake + take);
      }
    }
    return dp[n - 1][tar];
  }

  int countPartitions(int n, int d, vector<int> &arr)
  {
    int totSum = 0;
    for (auto it : arr)
    {
      totSum += it;
    }

    if (totSum - d < 0 || (totSum - d) % 2)
      return false;
    return findWays(arr, (totSum - d) / 2);
  }
  int findTargetSumWays(vector<int> &nums, int target)
  {
    return countPartitions(nums.size(), target, nums);
  }
};