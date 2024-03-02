class Solution
{
public:
  bool isPossible(vector<int> &nums, int k, int mid)
  {
    int cnt = 0;
    int sum = 0;

    for (auto it : nums)
    {
      if ((sum + it) > mid)
      {
        if (it > mid)
          return false;
        cnt++;
        sum = it;
      }
      else
      {
        sum += it;
      }
    }

    return cnt < k;
  }

  int splitArray(vector<int> &nums, int k)
  {
    if (k > nums.size())
      return -1;

    int low = 1e9, high = 0;

    for (auto it : nums)
    {
      low = min(low, it);
      high += it;
    }

    while (low <= high)
    {
      int mid = (low + high) / 2;

      if (isPossible(nums, k, mid))
      {
        high = mid - 1;
      }
      else
      {
        low = mid + 1;
        ;
      }
    }

    return low;
  }
};