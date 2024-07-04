class Solution
{
public:
  // https://leetcode.com/problems/peaks-in-array/
  vector<int> bit;
  vector<int> arr;
  vector<int> p;
  int n;
  void update(int id, int val)
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
  bool isPeak(int ind)
  {
    return (arr[ind] > arr[ind + 1] && arr[ind] > arr[ind - 1]);
  }
  void up(int i)
  {
    if (isPeak(i) && p[i] == 0)
    {
      p[i] = 1;
      update(i + 1, 1);
    }
    else if (!isPeak(i) && p[i] == 1)
    {
      p[i] = 0;
      update(i + 1, -1);
    }
  }
  vector<int> countOfPeaks(vector<int> &nums, vector<vector<int>> &q)
  {
    n = nums.size();
    arr = nums;
    bit.resize(n + 1, 0);
    p = vector<int>(n, 0);

    for (int i = 1; i < n - 1; i++)
    {
      if (isPeak(i))
      {
        update(i + 1, 1);
        p[i] = 1;
      }
    }

    vector<int> ans;
    for (auto it : q)
    {
      if (it[0] == 1)
      {
        int l = it[1] + 1;
        int r = it[2] - 1;
        ans.push_back(max(0, query(r + 1) - query(l)));
      }
      else if (it[0] == 2)
      {
        int ind = it[1];
        int val = it[2];
        arr[ind] = val;
        if (ind > 0 && ind < n - 1)
          up(ind);
        if (ind + 1 > 0 && ind + 1 < n - 1)
          up(ind + 1);
        if (ind - 1 > 0 && ind - 1 < n - 1)
          up(ind - 1);
      }
    }

    return ans;
  }
};