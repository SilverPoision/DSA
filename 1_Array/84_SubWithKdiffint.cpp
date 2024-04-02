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

//=====================
class Solution
{
public:
  // https://www.youtube.com/watch?v=0Kmbzm5nKqw
  int subarraysWithKDistinct(vector<int> &nums, int k)
  {
    int n = nums.size();

    unordered_map<int, int> hash;
    int i = 0, j = 0;
    int i_bada = 0;
    int res = 0;

    while (j < n)
    {
      hash[nums[j]]++;

      while (hash.size() > k)
      {
        hash[nums[i]]--;
        if (hash[nums[i]] == 0)
        {
          hash.erase(nums[i]);
        }
        i++;
        i_bada = i;
      }

      while (hash[nums[i]] > 1)
      {
        hash[nums[i]]--;
        i++;
      }

      if (hash.size() == k)
      {
        res += (1 + (i - i_bada));
      }
      j++;
    }

    return res;
  }
};