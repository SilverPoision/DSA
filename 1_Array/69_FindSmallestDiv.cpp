class Solution
{
public:
  bool isUnderThreshold(vector<int> &nums, int threshold, float mid)
  {
    float res = 0.0;

    for (auto it : nums)
    {
      res += ceil((float)it / mid);
    }

    return res <= threshold;
  }
  int smallestDivisor(vector<int> &nums, int threshold)
  {
    int low = 1, high = 1e6;

    while (low <= high)
    {
      int mid = (low + high) / 2;

      if (isUnderThreshold(nums, threshold, (float)mid))
      {
        high = mid - 1;
      }
      else
      {
        low = mid + 1;
      }
    }

    return low;
  }
};