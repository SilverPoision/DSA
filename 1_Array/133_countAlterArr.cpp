class Solution
{
public:
  // https://leetcode.com/problems/count-alternating-subarrays/description/
  long long countAlternatingSubarrays(vector<int> &nums)
  {
    long long ans = 1;
    int i = 0, j = 1;

    int last = nums[0];

    while (j < nums.size())
    {
      if (last == nums[j])
      {
        i = j;
      }
      ans += j - i + 1;
      last = nums[j];
      j++;
    }

    return ans;
  }
};

class Solution
{
public:
  long long countAlternatingSubarrays(vector<int> &nums)
  {
    long long ans = 1;
    int i = 0, j = 1;

    int last = nums[0];

    while (j < nums.size())
    {
      if (last != nums[j])
      {
        ans += j - i + 1;
        last = nums[j];
        j++;
      }
      else
      {
        last = nums[j];
        i = j;
        ans += j - i + 1;
        j++;
      }
    }

    return ans;
  }
};