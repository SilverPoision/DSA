class Solution
{
public:
  // https://leetcode.com/problems/find-k-th-smallest-pair-distance/?envType=daily-question&envId=2024-08-14
  int countPairsWithinDistance(vector<int> &numbers, int targetDistance)
  {
    int count = 0;
    int left = 0;

    for (int right = 1; right < numbers.size(); right++)
    {
      while (numbers[right] - numbers[left] > targetDistance)
      {
        left++;
      }
      count += right - left;
    }

    return count;
  }
  int smallestDistancePair(vector<int> &nums, int k)
  {
    int n = nums.size();
    int ans = 0;

    sort(nums.begin(), nums.end());

    int l = 0, r = nums.back() - nums[0];

    while (l < r)
    {
      int mid = l + (r - l) / 2;

      if (countPairsWithinDistance(nums, mid) >= k)
      {
        r = mid;
      }
      else
      {
        l = mid + 1;
      }
    }

    return l;
  }
};