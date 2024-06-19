class Solution
{
public:
  // https://leetcode.com/problems/continuous-subarray-sum/submissions/1281610388/?envType=daily-question&envId=2024-06-08
  bool checkSubarraySum(vector<int> &nums, int k)
  {
    unordered_map<int, int> hash;

    int prefix = 0;
    hash[0] = -1;

    for (int i = 0; i < nums.size(); i++)
    {
      prefix = (prefix + nums[i]) % k;
      if (hash.find(prefix) != hash.end())
      {
        if (i - hash[prefix] >= 2)
          return true;
      }
      else
      {
        hash[prefix] = i;
      }
    }

    return false;
  }
};