class Solution
{
public:
  int numSubarrayProductLessThanK(vector<int> &nums, int k)
  {
    if (k <= 1)
      return 0;

    int ans = 0;

    int i = 0, j = 0;
    int prod = 1;
    while (j < nums.size())
    {
      prod *= nums[j];

      while (prod >= k && i < j)
      {
        prod /= nums[i++];
      }

      if (prod < k)
        ans += j - i + 1;
      j++;
    }

    return ans;
  }
};