double minimiseMaxDistance(vector<int> &arr, int k)
{
  // Write your code here.
  // https://www.codingninjas.com/studio/problems/minimise-max-distance_7541449
  int n = arr.size();
  vector<int> howMany(n - 1, 0);

  for (int gasSt = 1; gasSt <= k; gasSt++)
  {
    long double maxSection = -1;
    int ind = -1;
    for (int i = 0; i < n - 1; i++)
    {
      long double diff = (arr[i + 1] - arr[i]);
      long double section = diff / (long double)(howMany[i] + 1);
      if (section > maxSection)
      {
        maxSection = section;
        ind = i;
      }
    }
    howMany[ind]++;
  }

  long double ans = 0;
  for (int i = 0; i < n - 1; i++)
  {
    long double diff = (arr[i + 1] - arr[i]);
    long double section = diff / (long double)(howMany[i] + 1);
    ans = max(ans, section);
  }

  return ans;
}

// Optimized with Max-Heap
#include <bits/stdc++.h>

double minimiseMaxDistance(vector<int> &arr, int k)
{
  // Write your code here.
  int n = arr.size();
  vector<int> howMany(n - 1, 0);
  priority_queue<pair<long double, int>> pq;

  for (int i = 0; i < n - 1; i++)
  {
    pq.push({arr[i + 1] - arr[i], i});
  }

  for (int gasSt = 1; gasSt <= k; gasSt++)
  {
    int i = pq.top().second;
    pq.pop();
    howMany[i]++;
    long double diff = (arr[i + 1] - arr[i]);
    long double section = diff / (long double)(howMany[i] + 1);
    pq.push({section, i});
  }

  return pq.top().first;
}

// Most Optimal BS
#include <bits/stdc++.h>

int noOfGasStReq(long double mid, vector<int> &arr)
{
  int cnt = 0;

  for (int i = 1; i < arr.size(); i++)
  {
    int stationsReq = (arr[i] - arr[i - 1]) / mid;
    if ((arr[i] - arr[i - 1]) == mid * stationsReq) // https://youtu.be/kMSBvlZ-_HA?si=xBq5VPbJZDV9pvrs&t=3121
    {
      stationsReq--;
    }
    cnt += stationsReq;
  }

  return cnt;
}

double minimiseMaxDistance(vector<int> &arr, int k)
{
  // Write your code here.
  int n = arr.size();
  long double low = 0, high = 0;

  for (int i = 1; i < n; i++)
  {
    high = max(high, (long double)(arr[i] - arr[i - 1]));
  }

  long double diff = 1e-6;

  while ((high - low) > diff)
  {
    long double mid = (low + high) / (2.0);

    int cnt = noOfGasStReq(mid, arr);

    if (cnt > k)
      low = mid;
    else
      high = mid;
  }

  return high;
}
