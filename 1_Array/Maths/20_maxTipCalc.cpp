class Solution
{
public:
  // https://www.geeksforgeeks.org/problems/maximum-tip-calculator2631/1
  long long maxTip(int n, int x, int y, vector<int> &arr, vector<int> &brr)
  {
    // code here
    vector<pair<int, pair<int, int>>> t;

    for (int i = 0; i < n; i++)
    {
      t.push_back({abs(arr[i] - brr[i]), {arr[i], brr[i]}});
    }

    sort(t.rbegin(), t.rend());

    long long ans = 0;
    for (int i = 0; i < n; i++)
    {
      int b = t[i].second.second;
      int a = t[i].second.first;
      if (x == 0)
      {
        ans += b;
      }
      else if (y == 0)
      {
        ans += a;
      }
      else
      {
        if (a > b)
        {
          ans += a;
          x--;
        }
        else
        {
          ans += b;
          y--;
        }
      }
    }

    return ans;
  }
};