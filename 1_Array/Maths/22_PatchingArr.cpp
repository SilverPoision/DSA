class Solution
{
public:
  // https://leetcode.com/problems/patching-array/?envType=daily-question&envId=2024-06-16
  // https://www.youtube.com/watch?v=6s97yEBQaGQ
  int minPatches(vector<int> &nums, int n)
  {
    long long minPatch = 0, maxEle = 0, i = 0, sz = nums.size();

    while (maxEle < n)
    {
      if (i < sz && maxEle + 1 >= nums[i])
      {
        maxEle += nums[i];
        i++;
      }
      else
      {
        maxEle += maxEle + 1;
        minPatch++;
      }
    }

    return minPatch;
  }
};