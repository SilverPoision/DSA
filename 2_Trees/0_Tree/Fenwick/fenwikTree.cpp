#include <iostream>
#include <bits/stdc++.h>

// Binary index tree
using namespace std;
// https://www.youtube.com/watch?v=9uaXG62Y8Uw

class Fenwick
{
public:
  vector<int> bit;
  int n;

  Fenwick(int n)
  {
    bit.resize(n, 0);
    this->n = n;
  }

  void upadte(int id, int val)
  {
    while (id <= n)
    {
      bit[id] += val;
      id += (id & (-id));
    }
  }

  int query(int id)
  {
    int ans = 0;
    while (id > 0)
    {
      ans += bit[id];
      id -= (id & (-id));
    }

    return ans;
  }

  int range(int l, int r)
  {
    return query(r) - query(l - 1);
  }
};

int main()
{
  vector<int> arr = {0, 2, 3, 4, 56, 4, 3, 2, 1};
  int n = arr.size();
  Fenwick f(n);

  for (int i = 1; i < n; i++)
  {
    f.upadte(i, arr[i]);
  }
  cout << endl;
  cout << f.range(3, 5);
  return 0;
}