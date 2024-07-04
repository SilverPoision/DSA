class Solution
{
public:
  // can also be solved by merge sort technique
  // https://www.youtube.com/watch?v=WpttRpfw28U&list=PLEL7R4Pm6EmBxBrEq8g2L3MF3W3Shnk58&index=3
  //  https://leetcode.com/problems/count-of-smaller-numbers-after-self/submissions/1303019220/
  vector<int> bit;
  int n;
  void update(int id, int val)
  {
    while (id <= n)
    {
      bit[id] += val;
      id += (id & -id);
    }
  }
  int query(int id)
  {
    int ans = 0;
    while (id > 0)
    {
      ans += bit[id];
      id -= (id & -id);
    }

    return ans;
  }
  vector<int> countSmaller(vector<int> &nums)
  {
    int n = nums.size();
    bit.resize(n + 1, 0);
    this->n = n;
    vector<pair<int, int>> p;

    for (int i = 0; i < n; i++)
    {
      p.push_back({nums[i], i});
    }

    sort(p.begin(), p.end());
    vector<int> ans(n);

    for (auto it : p)
    {
      update(it.second + 1, 1);
      ans[it.second] = query(n) - query(it.second + 1);
    }

    return ans;
  }
};