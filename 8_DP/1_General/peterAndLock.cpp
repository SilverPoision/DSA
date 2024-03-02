#include <bits/stdc++.h>
using namespace std;

bool f(int i, vector<int> &arr, int n, int sum)
{
  if (i >= n)
  {
    return sum == 0 || sum == 360;
  }

  bool add = f(i + 1, arr, n, sum + arr[i]);
  bool sub = f(i + 1, arr, n, sum - arr[i]);
  return add || sub;
}

int main()
{
  vector<int> arr = {10, 10, 10};
  int n = arr.size();
  cout << f(0, arr, n, 0);
  return 0;
}

// BitMasking
#include <bits/stdc++.h>
using namespace std;

int main()
{
  vector<int> arr = {120, 120, 120};
  int n = arr.size();
  bool flag = 0;

  for (int i = 0; i < (1 << n); i++)
  {
    int sum = 0;
    for (int bit = 0; bit < n; bit++)
    {
      if (i & (1 << bit))
      {
        sum += arr[bit];
      }
      else
      {
        sum -= arr[bit];
      }
    }
    if (sum % 360 == 0)
    {
      flag = 1;
      break;
    }
  }
  cout << flag;
  return 0;
}