class Solution
{
public:
  / https : // leetcode.com/problems/subarray-sums-divisible-by-k/submissions/1295675757/?envType=daily-question&envId=2024-06-09
            int
            subarraysDivByK(vector<int> &nums, int k)
  {
    int ans = 0;

    unordered_map<int, int> hash;
    int prefix = 0;
    hash[0] = 1;

    for (auto it : nums)
    {
      prefix = (prefix + it) % k;
      if (prefix < 0)
        prefix += k;

      if (hash.find(prefix) != hash.end())
      {
        ans += hash[prefix];
      }
      hash[prefix]++;
    }

    return ans;
  }
};