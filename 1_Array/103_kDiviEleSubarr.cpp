class Solution
{
public:
  // https://leetcode.com/problems/k-divisible-elements-subarrays/
  int countDistinct(vector<int> &nums, int k, int p)
  {
    int n = nums.size();
    unordered_map<string, int> hash;

    for (int i = 0; i < n; i++)
    {
      string st = "";
      int cnt = 0;
      for (int j = i; j < n && cnt <= k; j++)
      {
        if (nums[j] % p == 0)
          cnt++;
        st += to_string(nums[j]) + '-';
        if (cnt <= k)
          hash[st]++;
      }
    }

    return hash.size();
  }
};