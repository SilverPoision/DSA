class Solution
{
public:
  // https://leetcode.com/problems/find-the-median-of-the-uniqueness-array/description/
  long long atMostK(vector<int> &nums, int k)
  {
    int n = nums.size();
    long long i = 0, j = 0, res = 0;

    unordered_map<int, int> hash;

    while (j < n)
    {
      hash[nums[j]]++;

      while (hash.size() > k && i <= j)
      {
        if (--hash[nums[i]] == 0)
        {
          hash.erase(nums[i]);
        }
        i++;
      }

      res += j - i + 1;
      j++;
    }

    return res;
  }
  int medianOfUniquenessArray(vector<int> &nums)
  {
    int n = nums.size();
    long long total = (long long)n * (n + 1) / 2;

    int l = 1, r = unordered_set<int>(nums.begin(), nums.end()).size();

    while (l < r)
    {
      int mid = l + (r - l) / 2;

      if (atMostK(nums, mid) * 2 >= total) // no of subarrays at most k should be greater than or equal to
      // total subArray /2
      {
        r = mid;
      }
      else
      {
        l = mid + 1;
      }
    }

    return l;
  }
};