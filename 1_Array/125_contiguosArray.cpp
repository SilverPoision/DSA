class Solution
{
public:
  // https://leetcode.com/problems/contiguous-array/?envType=daily-question&envId=2024-03-16
  int findMaxLength(vector<int> &nums)
  {
    unordered_map<int, int> hash;

    hash[0] = -1;
    int maxi = 0;
    int sum = 0;

    for (int i = 0; i < nums.size(); i++)
    {
      sum += nums[i] == 0 ? -1 : 1;

      if (hash.find(sum) != hash.end())
      {
        maxi = max(maxi, i - hash[sum]);
      }
      else
      {
        hash[sum] = i;
      }
    }

    return maxi;
  }
};