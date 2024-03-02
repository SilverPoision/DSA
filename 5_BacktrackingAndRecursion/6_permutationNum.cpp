class Solution
{
public:
  void helper(int i, vector<int> &nums, vector<vector<int>> &ans)
  {
    if (i >= nums.size())
    {
      ans.push_back(nums);
      return;
    }

    for (int ind = i; ind < nums.size(); ind++)
    {
      swap(nums[i], nums[ind]);
      helper(i + 1, nums, ans);
      swap(nums[i], nums[ind]);
    }
  }
  vector<vector<int>> permute(vector<int> &nums)
  {
    vector<vector<int>> ans;
    helper(0, nums, ans);
    return ans;
  }
};