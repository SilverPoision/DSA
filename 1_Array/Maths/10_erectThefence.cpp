#define pii pair<int, int>

class Solution
{
public:
  // https://www.youtube.com/watch?v=et3dtYzVGQQ
  // https://leetcode.com/problems/erect-the-fence/
  int evalEq(pii &p1, pii &p2, pii p3)
  {
    int x1 = p1.first;
    int x2 = p2.first;
    int x3 = p3.first;

    int y1 = p1.second;
    int y2 = p2.second;
    int y3 = p3.second;

    return ((y2 - y1) * (x3 - x2) - (y3 - y2) * (x2 - x1));
  }
  vector<vector<int>> outerTrees(vector<vector<int>> &trees)
  {
    sort(trees.begin(), trees.end());

    deque<pii> lower, upper;

    for (auto it : trees)
    {
      int l = lower.size();
      int u = upper.size();

      while (l >= 2 && evalEq(lower[l - 2], lower[l - 1], {it[0], it[1]}) < 0)
      {
        l--;
        lower.pop_back();
      }
      while (u >= 2 && evalEq(upper[u - 2], upper[u - 1], {it[0], it[1]}) > 0)
      {
        u--;
        upper.pop_back();
      }
      lower.push_back({it[0], it[1]});
      upper.push_back({it[0], it[1]});
    }

    set<pii> st;
    for (auto it : lower)
      st.insert(it);
    for (auto it : upper)
      st.insert(it);

    vector<vector<int>> ans;
    for (auto it : st)
      ans.push_back({it.first, it.second});

    return ans;
  }
};