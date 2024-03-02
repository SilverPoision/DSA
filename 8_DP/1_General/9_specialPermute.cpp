#define ll long long
class Solution
{
public:
  // https://leetcode.com/problems/special-permutations/
  int mod = 1e9 + 7;
  int f(int i, vector<int> &nums, vector<vector<ll>> &dp, int mask,
        int prev)
  {
    if (i == nums.size())
    {
      return 1;
    }

    if (dp[prev + 1][mask] != -1)
      return dp[prev + 1][mask];

    ll take = 0;

    for (int k = 0; k < nums.size(); k++)
    {
      if ((mask & (1 << k)) == 0 && (prev == -1 ||
                                     (nums[k] % nums[prev] == 0 || nums[prev] % nums[k] == 0)))
      {
        take += f(i + 1, nums, dp, (mask | (1 << k)), k) % mod;
      }
    }

    return dp[prev + 1][mask] = take % mod;
  }
  int specialPerm(vector<int> &nums)
  {
    vector<vector<ll>> dp(nums.size() + 1,
                          vector<ll>(1 << nums.size() + 1, -1));
    return f(0, nums, dp, 0, -1);
  }
};

// tle
#define ll long long
class Solution
{
public:
  // tle
  int f(int i, vector<int> &nums)
  {
    if (i == nums.size())
    {
      return 1;
    }

    ll take = 0;

    for (int k = i; k < nums.size(); k++)
    {
      swap(nums[i], nums[k]);
      if ((i == 0) || (i - 1 >= 0 && (nums[i] % nums[i - 1] == 0 || nums[i - 1] % nums[i] == 0)))
      {
        take += f(i + 1, nums);
      }
      swap(nums[i], nums[k]);
    }

    return take;
  }
  int specialPerm(vector<int> &nums)
  {
    return f(0, nums) % (int)1e9 + 7;
  }
};