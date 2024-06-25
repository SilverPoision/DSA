#include <bits/stdc++.h>
using namespace std;

class SegmentTree
{
  vector<int> seg;
  int n;

public:
  SegmentTree() {}
  SegmentTree(int n)
  {
    this->n = n;
    seg.resize(4 * n, 0);
  }
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

  void update(int idx, int val, int low, int high, int ind)
  {
    if (low == high)
    {
      this->seg[ind] = val;
      return;
    }

    int mid = low + (high - low) / 2;

    if (low <= idx && idx <= mid)
    {
      update(idx, val, low, mid, 2 * ind + 1);
    }
    else
    {
      update(idx, val, mid + 1, high, 2 * ind + 2);
    }

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

  void build(vector<int> &arr)
  {
    buildTree(arr, 0, 0, n - 1);
  }
  int query(int l, int r)
  {
    return query(0, 0, n - 1, l, r);
  }
  void update(int idx, int val)
  {
    update(idx, val, 0, n - 1, 0);
  }
};

int main()
{
  vector<int> arr = {1, 3, 5, 2, 7, 9, 5, 2, 3, 6, 1};
  int n = arr.size();
  vector<pair<int, int>> q = {{1, 6}, {1, 5}, {0, 4}, {3, 6}, {6, 8}};
  SegmentTree s(n);
  s.build(arr);
  // arr[1] = 10;
  // s.update(1, 10, 0, n - 1, 0);
  for (auto it : q)
  {
    cout << s.query(it.first, it.second) << " ";
  }
  // cout << s.query(0, 0, n - 1, 0, 2) << " ";

  return 0;
}
