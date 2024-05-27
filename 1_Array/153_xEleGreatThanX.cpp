class Solution
{
public:
  // https://leetcode.com/problems/special-array-with-x-elements-greater-than-or-equal-x/?envType=daily-question&envId=2024-05-27
  int specialArray(vector<int> &nums)
  {
    sort(nums.begin(), nums.end());

    int n = nums.size();
    int l = 0, r = n;

    while (l <= r)
    {
      int mid = l + (r - l) / 2;

      int lb = lower_bound(nums.begin(), nums.end(), mid) - nums.begin();

      if (n - lb == mid)
        return mid;
      else if (n - lb > mid)
      {
        l = mid + 1;
      }
      else
      {
        r = mid - 1;
      }
    }

    return -1;
  }
};

// optimal
class Solution
{
public:
  int specialArray(vector<int> &nums)
  {
    int n = nums.size();
    vector<int> hash(n + 1, 0);

    for (auto it : nums)
    {
      hash[min(it, n)]++;
    }

    int sum = 0;
    for (int i = n; i >= 0; i--)
    {
      sum += hash[i];
      if (sum == i)
        return i;
    }

    return -1;
  }
};