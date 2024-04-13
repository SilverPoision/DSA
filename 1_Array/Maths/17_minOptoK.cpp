class Solution
{
public:
  // https://leetcode.com/problems/minimum-operations-to-make-median-of-array-equal-to-k/
  long long minOperationsToMakeMedianK(vector<int> &nums, int k)
  {
    int n = nums.size();
    sort(nums.begin(), nums.end());

    int mid = n / 2;
    long long mini = abs(nums[mid] - k);

    if (nums[mid] > k)
    {
      nums[mid] = k;
      int idx = mid - 1;

      while (idx >= 0 && nums[idx] > nums[idx + 1])
      {
        mini += nums[idx] - nums[idx + 1];
        nums[idx] = nums[idx + 1];
        idx--;
      }
    }
    else
    {
      nums[mid] = k;
      int idx = mid + 1;

      while (idx < n && nums[idx] < nums[idx - 1])
      {
        mini += nums[idx - 1] - nums[idx];
        nums[idx] = nums[idx - 1];
        idx++;
      }
    }

    return mini;
  }
};