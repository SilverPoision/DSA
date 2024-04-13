class Solution
{
public:
  // https://leetcode.com/problems/count-subarrays-with-fixed-bounds/
  // https://www.youtube.com/watch?v=z6LwIkEn9qc
  long long countSubarrays(vector<int> &nums, int minK, int maxK)
  {
    int ans = 0;

    int minI = -1;
    int maxI = -1;
    int culI = -1;

    for (int i = 0; i < nums.size(); i++)
    {

      if (nums[i] > maxK || nums[i] < minK)
        culI = i;
      if (nums[i] == minK)
        minI = i;
      if (nums[i] == maxK)
        maxI = i;

      int smaller = min(minI, maxI);
      // to get the smaller index so that when we minus the culprit
      // idx we know if the culprit is in the bound or not
      long long temp = smaller - culI;

      ans += temp < 0 ? 0 : temp;
    }

    return ans;
  }
};