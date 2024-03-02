#include <bits/stdc++.h>

vector<int> divisibleSet(vector<int> &arr)
{
  int n = arr.size();
  sort(arr.begin(), arr.end());
  vector<int> temp(n, 1), hash(n);
  temp.push_back(arr[0]);
  int lastInd = 0;
  int ans = 1;

  for (int i = 0; i < n; i++)
  {
    hash[i] = i;
    for (int j = 0; j < i; j++)
    {
      if (arr[i] % arr[j] == 0 && temp[i] < 1 + temp[j])
      {
        temp[i] = 1 + temp[j];
        hash[i] = j;
      }
    }
    if (ans < temp[i])
    {
      ans = temp[i];
      lastInd = i;
    }
  }

  vector<int> lis;
  lis.push_back(arr[lastInd]);
  while (hash[lastInd] != lastInd)
  {
    lastInd = hash[lastInd];
    lis.push_back(arr[lastInd]);
  }

  reverse(lis.begin(), lis.end());
  return lis;
}