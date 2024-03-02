class Solution
{
public:
  // https://leetcode.com/problems/find-polygon-with-the-largest-perimeter/
  long long
  largestPerimeter(vector<int> &nums)
  {
    int n = nums.size();
    sort(nums.begin(), nums.end());

    vector<long long> sums(n, 0);
    sums[0] = nums[0];
    for (int i = 1; i < n; i++)
    {
      sums[i] = sums[i - 1] + nums[i];
    }

    for (int i = n - 1; i >= 2; i--)
    {
      if (sums[i - 1] > nums[i])
      {
        return sums[i];
      }
    }

    return -1;
  }
};

// same
class Solution
{
public:
  long long largestPerimeter(vector<int> &nums)
  {
    int n = nums.size();
    sort(nums.begin(), nums.end());

    long long sum = 0;
    for (int i = 0; i < n; i++)
    {
      sum += nums[i];
    }

    for (int i = n - 1; i >= 2; i--)
    {
      if (sum - nums[i] > nums[i])
      {
        return sum;
      }
      sum = sum - nums[i];
    }

    return -1;
  }
};