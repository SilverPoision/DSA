// https://leetcode.com/problems/check-if-array-pairs-are-divisible-by-k/description/

class Solution
{
public:
  bool canArrange(vector<int> &arr, int k)
  {
    if (arr.size() % 2 != 0)
      return false;

    int n = arr.size();
    vector<int> freq(k, 0);

    for (auto it : arr)
    {
      int rem = ((it % k) + k) % k; //(x%k + k)%k is done to counter negative integers in the array. and to find the reminder

      if (freq[(k - rem) % k] != 0)
      {
        freq[(k - rem) % k]--;
      }
      else
      {
        freq[rem]++;
      }
    }

    for (auto it : freq)
    {
      if (it != 0)
        return false;
    }

    return true;
  }
};

class Solution
{
public:
  bool canArrange(vector<int> &arr, int k)
  {
    int n = arr.size();
    map<int, int> m;

    for (int i = 0; i < n; i++)
    {
      m[((arr[i] % k) + k) % k]++;
    }

    for (int i = 0; i < n; i++)
    {
      int rem = ((arr[i] % k) + k) % k;

      if (rem * 2 == k)
      {
        if (m[rem] & 1)
          return false;
      }
      else if (rem == 0)
      {
        if (m[0] & 1)
          return false;
      }
      else if (m[rem] != m[k - rem])
      {
        return false;
      }
    }

    return true;
  }
};