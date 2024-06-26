class Solution
{
public:
  // https://leetcode.com/problems/block-placement-queries/
  // https://www.youtube.com/watch?v=-1bvAUp3ZfU&list=PLEL7R4Pm6EmBxBrEq8g2L3MF3W3Shnk58&index=4
  vector<bool> getResults(vector<vector<int>> &qs)
  {
    vector<bool> res;
    set<int> blocks{0}; // sentinel
    for (const auto &q : qs)
      if (q[0] == 1)
        blocks.insert(q[1]);
    for (auto it = next(begin(blocks)); it != end(blocks); ++it)
      update(*it, *it - *prev(it));
    for (int i = qs.size() - 1; i >= 0; --i)
    {
      int t = qs[i][0], x = qs[i][1], sz = t == 1 ? 0 : qs[i][2];
      auto it = blocks.lower_bound(x);
      if (t == 1)
      {
        if (next(it) != end(blocks))
          update(*next(it), *next(it) - *prev(it));
        blocks.erase(it);
      }
      else
        res.push_back(x - *prev(it) >= sz || getmax(x) >= sz);
    }
    return vector<bool>(rbegin(res), rend(res));
  }
  int bit[50001] = {};
  int getmax(int r)
  {
    int ret = 0;
    for (; r >= 0; r = (r & (r + 1)) - 1)
      ret = max(ret, bit[r]);
    return ret;
  }
  void update(int idx, int val)
  {
    for (; idx < 50001; idx = idx | (idx + 1))
      bit[idx] = max(bit[idx], val);
  }
};