class Solution
{
public:
  // https://leetcode.com/problems/sum-of-digit-differences-of-all-pairs/
  long long sumDigitDifferences(vector<int> &nums)
  {
    int n = nums.size();

    map<pair<int, int>, int> hash;
    for (int i = 0; i < n; i++)
    {
      int num = nums[i];
      for (int k = 0; k < 9; k++)
      {
        hash[{k, num % 10}]++;
        num /= 10;
      }
    }

    long long ans = 0;
    for (int i = 0; i < n; i++)
    {
      int num = nums[i];
      for (int k = 0; k < 9; k++)
      {
        ans += n - hash[{k, num % 10}];
        num /= 10;
      }
    }

    return ans / 2;
  }
};