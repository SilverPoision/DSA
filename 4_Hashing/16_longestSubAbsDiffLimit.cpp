class Solution
{
public:
  // https://leetcode.com/problems/longest-continuous-subarray-with-absolute-diff-less-than-or-equal-to-limit/?envType=daily-question&envId=2024-06-23
  int longestSubarray(vector<int> &nums, int limit)
  {
    int n = nums.size();
    map<int, int> hash;

    int i = 0, j = 0;
    int ans = 0;

    while (j < n)
    {
      hash[nums[j]]++;

      auto fr = hash.begin();
      auto bc = hash.rbegin();

      while (i < n && (bc->first - fr->first) > limit)
      {
        if (--hash[nums[i]] == 0)
          hash.erase(nums[i]);
        i++;
        fr = hash.begin();
        bc = hash.rbegin();
      }

      ans = max(ans, j - i + 1);
      j++;
    }

    return ans;
  }
};