class Solution
{
public:
  // https://leetcode.com/problems/special-array-ii/submissions/1263907795/
  vector<bool> isArraySpecial(vector<int> &nums, vector<vector<int>> &q)
  {
    int n = nums.size();

    vector<int> prefixSum(n, 0);
    vector<bool> ans;

    for (int i = 1; i < n; i++)
    {
      prefixSum[i] = prefixSum[i - 1];
      if (nums[i - 1] % 2 == nums[i] % 2)
      {
        prefixSum[i]++;
      }
    }

    for (auto it : q)
    {
      int l = it[0];
      int r = it[1];
      if ((prefixSum[r] - prefixSum[l]) >= 1)
        ans.push_back(false);
      else
        ans.push_back(true);
    }

    return ans;
  }
};