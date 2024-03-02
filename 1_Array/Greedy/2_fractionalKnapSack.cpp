#include <bits/stdc++.h>

bool compare(pair<int, int> &a, pair<int, int> &b)
{
  double r1 = (double)a.second / a.first;
  double r2 = (double)b.second / b.first;

  return r1 > r2;
}

double maximumValue(vector<pair<int, int>> &items, int n, int w)
{
  // Write your code here.
  // ITEMS contains {weight, value} pairs.
  sort(items.begin(), items.end(), compare);

  double maxi = 0;
  int currWeight = 0;

  for (int i = 0; i < n; i++)
  {
    auto it = items[i];
    if (currWeight + it.first <= w)
    {
      currWeight += it.first;
      maxi += it.second;
    }
    else
    {
      int reqWeight = w - currWeight;
      maxi += ((double)it.second / it.first) * reqWeight;

      break;
    }
  }

  return maxi;
}