class Solution
{
public:
  void helper(int i, vector<int> &nums, vector<int> &out, vector<vector<int>> &ans)
  {
    if (i == nums.size())
    {
      ans.push_back(out);
      return;
    }

    out.push_back(nums[i]);
    helper(i + 1, nums, out, ans);
    out.pop_back();

    while (i + 1 < nums.size() && nums[i] == nums[i + 1])
    {
      i++;
    }

    helper(i + 1, nums, out, ans);
  }
  vector<vector<int>> subsetsWithDup(vector<int> &nums)
  {
    vector<vector<int>> ans;
    vector<int> out;
    sort(nums.begin(), nums.end());
    helper(0, nums, out, ans);
    return ans;
  }
};