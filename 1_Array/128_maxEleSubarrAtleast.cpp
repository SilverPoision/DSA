class Solution
{
public:
  // https://leetcode.com/problems/count-subarrays-where-max-element-appears-at-least-k-times/
  long long countSubarrays(vector<int> &nums, int k)
  {
    int n = nums.size();

    int i = 0, j = 0;

    int maxi = *max_element(nums.begin(), nums.end());

    long long ans = 0;

    while (j < n)
    {
      k -= (nums[j++] == maxi);

      while (k == 0)
      {
        k += (nums[i++] == maxi);
      }

      ans += i;
    }

    return ans;
  }
};