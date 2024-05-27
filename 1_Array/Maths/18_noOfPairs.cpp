class Solution
{
public:
  // https://leetcode.com/problems/find-the-number-of-good-pairs-ii/
  long long numberOfPairs(vector<int> &nums1, vector<int> &nums2, int k)
  {
    long long cnt = 0;

    unordered_map<int, int> hash;
    for (auto it : nums2)
    {
      hash[it * k]++;
    }

    for (auto it : nums1)
    {
      if (it % k)
        continue;
      for (int i = 1; i * i <= it; i++)
      {
        if (it % i)
          continue;

        int f = it / i;
        int f2 = it / f;

        cnt += hash[f];
        if (f != f2)
          cnt += hash[f2];
      }
    }

    return cnt;
  }
};