int longestSubarrayWithSumK(vector<int> a, long long k)
{
  // Optimal only for positive int
  int left = 0, right = 0;
  int maxi = 0;
  long long sum = a[0];
  int n = a.size();

  while (right < n)
  {
    while (left <= right && sum > k)
    {
      sum -= a[left];
      left++;
    }

    if (sum == k)
    {
      maxi = max(maxi, right - left + 1);
    }

    right++;
    if (right < n)
      sum += a[right];
  }

  return maxi;
}

// Its optimal if the array contains +ive and -tive both int;
#include <bits/stdc++.h>

int longestSubarrayWithSumK(vector<int> a, long long k)
{
  unordered_map<long long, int> preSumMap;
  long long sum = 0;
  int maxLen = 0;

  for (int i = 0; i < a.size(); i++)
  {
    sum += a[i];

    if (sum == k)
    {
      maxLen = max(maxLen, i + 1);
    }

    long long rem = sum - k;

    if (preSumMap.find(rem) != preSumMap.end())
    {
      int len = i - preSumMap[rem];
      maxLen = max(maxLen, len);
    }

    if (preSumMap.find(sum) == preSumMap.end())
    {
      preSumMap[sum] = i; // this will not let the updation interfeare with the max sum
    }
  }

  return maxLen;
}
