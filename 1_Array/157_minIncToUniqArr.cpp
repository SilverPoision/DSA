class Solution
{
public:
  // https://leetcode.com/problems/minimum-increment-to-make-array-unique/?envType=daily-question&envId=2024-06-14
  int minIncrementForUnique(vector<int> &nums)
  {
    vector<int> freq(
        *max_element(nums.begin(), nums.end()) + nums.size() + 1, 0);

    for (auto it : nums)
      freq[it]++;

    int ans = 0;

    for (int i = 0; i < freq.size(); i++)
    {
      if (freq[i] <= 1)
        continue;
      freq[i + 1] += freq[i] - 1;
      ans += freq[i] - 1;
    }

    return ans;
  }
};

class Solution
{
public:
  int minIncrementForUnique(vector<int> &nums)
  {
    sort(nums.begin(), nums.end());
    int cnt = 0;

    for (int i = 1; i < nums.size(); i++)
    {
      if (nums[i] <= nums[i - 1])
      {
        int inc = abs(nums[i - 1] - nums[i]) + 1;
        nums[i] += inc;
        cnt += inc;
      }
    }

    return cnt;
  }
};