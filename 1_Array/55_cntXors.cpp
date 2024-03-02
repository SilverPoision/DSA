#include <bits/stdc++.h>

int subarraysWithSumK(vector<int> arr, int k)
{
  int xors = 0;
  map<int, int> hash; // frontxor, cnt
  hash[0] = 1;
  int cnt = 0;

  for (int i = 0; i < arr.size(); i++)
  {
    xors = xors ^ arr[i];

    int findXor = xors ^ k;
    cnt += hash[findXor];

    hash[xors]++;
    ;
  }

  return cnt;
}