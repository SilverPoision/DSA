class Solution
{
public:
  // https://leetcode.com/problems/minimum-number-of-k-consecutive-bit-flips/?envType=daily-question&envId=2024-06-24
  int minKBitFlips(vector<int> &nums, int k)
  {
    int n = nums.size();

    int times = 0;
    int ans = 0;

    for (int i = 0; i < n; i++)
    {
      if (i - k >= 0)
      {
        if (nums[i - k] > 1)
        {
          nums[i - k] -= 2;
          times -= 1;
        }
      }
      if ((nums[i] == 1 && ((times & 1) == 1)) || (nums[i] == 0 && ((times & 1) == 0)))
      {
        if (i + k > n)
          return -1;
        nums[i] += 2;
        times++;
        ans++;
      }
    }

    return ans;
  }
};