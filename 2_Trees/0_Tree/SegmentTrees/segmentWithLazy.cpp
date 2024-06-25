#include <bits/stdc++.h>
using namespace std;
// https://github.com/aryan-0077/Competitive-Programming/blob/main/segTree_Generic_LazyPropogation.sublime-snippet

class SegmentTree
{
  vector<int> seg, unPrpUpd;
  vector<bool> isLazy;
  int n;

public:
  SegmentTree() {}
  SegmentTree(int l)
  {
    n = l;
    seg.resize(4 * n);
    unPrpUpd.resize(4 * n);
    isLazy.resize(4 * n);
  }
  void buildTree(vector<int> &a, int ind, int tl, int tr)
  {
    if (tl == tr)
    {
      seg[ind] = a[tl];
      return;
    }

    int tm = (tr + tl) / 2;
    buildTree(a, 2 * ind + 1, tl, tm);
    buildTree(a, 2 * ind + 2, tm + 1, tr);
    seg[ind] = seg[2 * ind + 1] + seg[2 * ind + 2];
  }

  void apply(int ind, int tl, int tr, int val)
  {
    if (tl != tr)
    {
      isLazy[ind] = true;
      unPrpUpd[ind] = val;
    }

    seg[ind] = val * (tr - tl + 1);
  }
  void pushDown(int ind, int tl, int tr)
  {
    if (!isLazy[ind])
      return;

    isLazy[ind] = false;
    int tm = (tl + tr) / 2;

    apply(ind * 2 + 1, tl, tm, unPrpUpd[ind]);
    apply(ind * 2 + 2, tm + 1, tr, unPrpUpd[ind]);

    unPrpUpd[ind] = 0;
  }

  void update(int ind, int tl, int tr, int l, int r, int val)
  {
    if (l <= tl && r >= tr)
    {
      apply(ind, tl, tr, val);
      return;
    }
    if (tl > r || tr < l)
      return;

    int tm = (tl + tr) / 2;

    update(ind * 2 + 1, tl, tm, l, r, val);
    update(ind * 2 + 2, tm + 1, tr, l, r, val);

    seg[ind] = seg[2 * ind + 1] + seg[2 * ind + 2];
  }

  int query(int ind, int tl, int tr, int l, int r)
  {
    if (tl >= l && tr <= r)
      return this->seg[ind];
    if (tr < l || tl > r)
      return INT_MIN;

    pushDown(ind, tl, tr);
    int tm = (tl + tr) / 2;
    int left = query(2 * ind + 1, tl, tm, l, r);
    int right = query(2 * ind + 2, tm + 1, tr, l, r);
    return left + right;
  }

  void build(vector<int> &arr)
  {
    buildTree(arr, 0, 0, n - 1);
  }
  int query(int l, int r)
  {
    return query(0, 0, n - 1, l, r);
  }
  void update(int l, int r, int val)
  {
    update(0, 0, n - 1, l, r, val);
  }
};

int main()
{
  vector<int> arr = {1, 3, 5, 2, 7, 9, 5, 2, 3, 6, 1};

  int n = arr.size();
  SegmentTree s(n);

  s.build(arr);
  cout << s.query(0, 4) << " ";
  s.update(0, 4, 10);
  cout << s.query(0, 4) << " ";

  return 0;
}
