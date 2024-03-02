class Solution
{
public:
  // https://leetcode.com/problems/subarrays-with-k-different-integers/description/
  int findAtmost(vector<int> &arr, int k)
  {
    int ans = 0;
    int n = arr.size();

    int i = 0, j = 0;
    map<int, int> hash;

    while (j < n)
    {
      hash[arr[j]]++;

      while (hash.size() > k)
      {
        hash[arr[i]]--;

        if (hash[arr[i]] == 0)
          hash.erase(arr[i]);
        i++;
      }

      ans += j - i + 1; // to count the all permutations
      j++;
    }

    return ans;
  }
  int subarraysWithKDistinct(vector<int> &nums, int k)
  {
    return findAtmost(nums, k) - findAtmost(nums, k - 1); // atmost k - atmost k-1
  }
};