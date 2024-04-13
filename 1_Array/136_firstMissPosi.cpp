class Solution
{
public:
  int firstMissingPositive(vector<int> &nums)
  {
    int n = nums.size();
    bool f = false;
    for (int i = 0; i < n; i++)
    {
      if (nums[i] == 1)
      {
        f = true;
      }
      if (nums[i] <= 0 || nums[i] > n)
      {
        nums[i] = 1;
      }
    }

    if (!f)
      return 1;

    for (int i = 0; i < n; i++)
    {
      int it = abs(nums[i]) - 1;
      if (nums[it] >= 0)
        nums[it] *= -1;
    }

    for (int i = 0; i < n; i++)
    {
      if (nums[i] > 0)
        return i + 1;
    }

    return n + 1;
  }
};