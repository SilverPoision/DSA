class Solution
{
public:
  // just more elegant
  // https://leetcode.com/problems/length-of-longest-subarray-with-at-most-k-frequency/
  int maxSubarrayLength(vector<int> &v, int k)
  {
    int n = v.size(), cnt = 0, ans = 0, start = 0, end = 0;
    unordered_map<int, int> mp;
    while (end < n)
    {
      mp[v[end++]] += 1;
      while (mp[v[end - 1]] > k)
      {
        mp[v[start++]] -= 1;
      }
      ans = max(ans, end - start);
    }
    return ans;
  }
};

class Solution
{
public:
  int maxSubarrayLength(vector<int> &nums, int k)
  {
    unordered_map<int, int> hash;
    int i = 0, j = 0;
    hash[nums[0]]++;
    int maxi = 1;
    int maxFreq = 1;

    while (j < nums.size() - 1)
    {
      hash[nums[++j]]++;
      maxFreq = max(maxFreq, hash[nums[j]]);
      if (maxFreq <= k)
      {
        maxi = max(maxi, j - i + 1);
      }
      else
      {
        while (i < j && maxFreq > k)
        {
          if (hash[nums[i]] == maxFreq)
            maxFreq--;
          hash[nums[i++]]--;
        }
        maxi = max(maxi, j - i + 1);
      }
    }

    return maxi;
  }
};