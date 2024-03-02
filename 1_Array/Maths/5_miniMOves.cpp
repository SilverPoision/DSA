class Solution
{
public:
  // https://leetcode.com/problems/minimum-moves-to-equal-array-elements-ii/
  int minMoves2(vector<int> &nums)
  {
    int n = nums.size();
    sort(nums.begin(), nums.end());

    int cnt = 0;

    int mean = n % 2 ? nums[n / 2] : (nums[n / 2 - 1] + nums[n / 2]) / 2;

    for (auto it : nums)
    {
      cnt += abs(mean - it);
    }

    return cnt;
  }
};