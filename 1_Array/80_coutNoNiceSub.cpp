class Solution
{
public:
  int findAtmost(vector<int> &arr, int k)
  {
    int n = arr.size();
    int odd = 0, ans = 0;

    int i = 0, j = 0;

    while (j < n)
    {
      odd += arr[j] & 1;

      while (odd > k)
      {
        odd -= arr[i++] & 1;
      }

      ans += j - i + 1;
      j++;
    }

    return ans;
  }

  int numberOfSubarrays(vector<int> &nums, int k)
  {
    return findAtmost(nums, k) - findAtmost(nums, k - 1);
  }
};

class Solution
{
public:
  int numberOfSubarrays(vector<int> &nums, int k)
  {
    int n = nums.size();
    int ans = 0;
    int odd = 0;

    map<int, int> hash;

    for (auto i : nums)
    {
      if ((i % 2) == 1)
      {
        odd++;
      }

      if (odd == k)
        ans++;

      if (hash.find(odd - k) != hash.end())
      {
        ans += hash[odd - k];
      }

      hash[odd]++;
    }
    return ans;
  }
};