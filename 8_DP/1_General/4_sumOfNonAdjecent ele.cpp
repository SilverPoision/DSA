// Memoization

int func(int index, vector<int> &nums, vector<int> &dp)
{
  if (index == 0)
  {
    return nums[0];
  }
  if (index < 0)
  {
    return 0;
  }

  if (dp[index] != -1)
  {
    return dp[index];
  }

  int notPick = nums[index] + func(index - 2, nums, dp);
  int pick = func(index - 1, nums, dp);

  return dp[index] = max(notPick, pick);
}

int maximumNonAdjacentSum(vector<int> &nums)
{
  vector<int> dp(nums.size() + 1, -1);
  int max = func(nums.size() - 1, nums, dp);
  return max;
}

// Tabulation

int func(vector<int> &nums, vector<int> &dp)
{
  dp[0] = nums[0];
  int pick, notPick, i;

  for (i = 1; i < nums.size(); i++)
  {
    notPick = nums[i];
    if (i - 2 >= 0)
      notPick += dp[i - 2];
    pick = dp[i - 1];
    dp[i] = max(notPick, pick);
  }

  return dp[i - 1];
}

int maximumNonAdjacentSum(vector<int> &nums)
{
  vector<int> dp(nums.size() + 1, -1);
  int max = func(nums, dp);
  return max;
}

// S.O
class Solution
{
public:
  int rob(vector<int> &nums)
  {
    vector<int> dp(nums.size());
    int curr = nums[0];
    int prev = 0;

    for (int i = 1; i < nums.size(); i++)
    {
      int take = nums[i];
      if (i - 2 >= 0)
        take += prev;

      int notTake = curr;
      prev = curr;
      curr = max(take, notTake);
    }

    return curr;
  }
};