class Solution
{
public:
  // https://leetcode.com/problems/minimum-difference-between-largest-and-smallest-value-in-three-moves/?envType=daily-question&envId=2024-07-03
  int minDifference(vector<int> &nums)
  {
    int n = nums.size();
    if (n <= 3)
      return 0;

    sort(nums.begin(), nums.end());
    long long mini = 1e18;
    long long low, high;

    for (int i = 0; i <= 3; i++)
    {
      low = nums[i];
      high = nums[(n - 4) + i];

      mini = min(mini, high - low);
    }

    return mini;
  }
};