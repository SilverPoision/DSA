class Solution
{
public:
  // https://leetcode.com/problems/the-number-of-beautiful-subsets/?envType=daily-question&envId=2024-05-23
  int solve(vector<int> &nums, int k, int i, unordered_map<int, int> &hash)
  {
    if (i == nums.size())
      return 1;

    int ans = 0;

    ans += solve(nums, k, i + 1, hash);
    if (hash[nums[i] - k] == 0)
    {
      hash[nums[i]]++;
      ans += solve(nums, k, i + 1, hash);
      hash[nums[i]]--;
    }

    return ans;
  }
  int beautifulSubsets(vector<int> &nums, int k)
  {
    sort(nums.begin(), nums.end());
    unordered_map<int, int> hash;
    return solve(nums, k, 0, hash) - 1;
  }
};