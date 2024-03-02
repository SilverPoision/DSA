/*
216. Combination Sum III
Medium
4.6K
93
Companies
Find all valid combinations of k numbers that sum up to n such that the following conditions are true:

Only numbers 1 through 9 are used.
Each number is used at most once.
Return a list of all possible valid combinations. The list must not contain the same combination twice, and the combinations may be returned in any order.



Example 1:

Input: k = 3, n = 7
Output: [[1,2,4]]
Explanation:
1 + 2 + 4 = 7
There are no other valid combinations.
*/

class Solution
{
public:
  void solve(int k, int n, vector<int> tmp, vector<vector<int>> &ans, int s)
  {
    if (n == 0 && k == 0)
    {
      ans.push_back(tmp);
      return;
    }
    if (n == 0)
      return;
    if (k == 0)
      return;
    for (int i = s; i <= 9; i++)
    {
      tmp.push_back(i);
      solve(k - 1, n - i, tmp, ans, i + 1);
      tmp.pop_back();
    }
  }
  vector<vector<int>> combinationSum3(int k, int n)
  {
    vector<vector<int>> ans;
    if (k >= n || n == 1)
    {
      return ans;
    }
    vector<int> tmp;
    solve(k, n, tmp, ans, 1);
    return ans;
  }
};

// Tab
class Solution
{
public:
  int combinationSum4(vector<int> &nums, int target)
  {
    vector<uint> dp(target + 1, 0);
    dp[0] = 1;

    for (int currTarget = 1; currTarget <= target; currTarget++)
    {
      for (auto it : nums)
      {
        if (currTarget >= it)
        {
          dp[currTarget] += dp[currTarget - it];
        }
      }
    }

    return dp[target];
  }
};