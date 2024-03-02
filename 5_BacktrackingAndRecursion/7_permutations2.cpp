class Solution
{
public:
  void helper(int i, vector<int> &nums, set<vector<int>> &s)
  {
    if (i >= nums.size())
    {
      s.insert(nums);
      return;
    }

    for (int ind = i; ind < nums.size(); ind++)
    {
      swap(nums[ind], nums[i]);
      helper(i + 1, nums, s);
      swap(nums[ind], nums[i]);
    }
  }
  vector<vector<int>> permuteUnique(vector<int> &nums)
  {
    set<vector<int>> s;
    vector<vector<int>> ans;
    helper(0, nums, s);
    for (auto it : s)
    {
      ans.push_back(it);
    }
    return ans;
  }
};