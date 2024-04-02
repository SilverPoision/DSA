class Solution
{
public:
  // https://leetcode.com/problems/find-all-duplicates-in-an-array/
  vector<int> findDuplicates(vector<int> &nums)
  {
    vector<int> ans;

    for (int i = 0; i < nums.size(); i++)
    {
      int k = abs(nums[i]) - 1;
      if (nums[k] < 0)
        ans.push_back(k + 1);
      nums[k] = -nums[k];
    }

    return ans;
  }
};