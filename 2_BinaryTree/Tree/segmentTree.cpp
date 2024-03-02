#include <bits/stdc++.h>
using namespace std;

class SegmentTree
{
public:
  int seg[100000];

  void buildTree(vector<int> &a, int ind, int low, int high)
  {
    if (low == high)
    {
      this->seg[ind] = a[low];
      return;
    }

    int mid = (high + low) / 2;
    buildTree(a, 2 * ind + 1, low, mid);
    buildTree(a, 2 * ind + 2, mid + 1, high);
    this->seg[ind] = max(this->seg[2 * ind + 1], this->seg[2 * ind + 2]);
  }

  int query(int ind, int low, int high, int l, int r)
  {
    if (low >= l && high <= r)
      return this->seg[ind];
    if (high < l || low > r)
      return INT_MIN;

    int mid = (low + high) / 2;
    int left = query(2 * ind + 1, low, mid, l, r);
    int right = query(2 * ind + 2, mid + 1, high, l, r);
    return max(left, right);
  }
};

int main()
{
  vector<int> arr = {1, 3, 5, 2, 7, 9, 5, 2, 3, 6, 1};
  int n = arr.size();
  vector<pair<int, int>> q = {{1, 6}, {1, 5}, {0, 4}, {3, 6}, {6, 8}};
  SegmentTree s;
  s.buildTree(arr, 0, 0, n - 1);
  for (auto it : q)
  {
    cout << s.query(0, 0, n - 1, it.first, it.second) << " ";
  }
  return 0;
}
