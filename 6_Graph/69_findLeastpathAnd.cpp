class Solution
{
public:
  // https://leetcode.com/problems/minimum-cost-walk-in-weighted-graph/
  vector<int> parent;
  int find(int node)
  {
    if (parent[node] == node)
      return node;

    return parent[node] = find(parent[node]);
  }

  void Union(int u, int v) { parent[u] = v; }

  vector<int> minimumCost(int n, vector<vector<int>> &edges,
                          vector<vector<int>> &q)
  {
    vector<int> ans;
    parent.resize(n);
    vector<int> cost(n);

    for (int i = 0; i < n; i++)
    {
      parent[i] = i;
      cost[i] = -1;
    }

    for (auto it : edges)
    {
      int u = it[0];
      int v = it[1];
      int w = it[2];

      int up = find(u);
      int uv = find(v);

      if (up != uv)
      {
        Union(up, uv);
        cost[uv] &= cost[up];
      }

      cost[uv] &= w;
    }

    for (auto it : q)
    {
      int u = it[0];
      int v = it[1];

      int uP = find(u);
      int uV = find(v);

      if (uP == uV)
      {
        ans.push_back(cost[uP]);
      }
      else
      {
        ans.push_back(-1);
      }
    }

    return ans;
  }
};