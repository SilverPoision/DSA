class Solution
{
public:
  // https://www.geeksforgeeks.org/problems/number-of-good-components--170647/1
  void dfs(int node, unordered_map<int, vector<int>> &adj, vector<bool> &vis, vector<int> &nodes)
  {
    vis[node] = true;
    nodes.push_back(node);

    for (auto it : adj[node])
    {
      if (!vis[it])
      {
        dfs(it, adj, vis, nodes);
      }
    }
  }

  int findNumberOfGoodComponent(int e, int v, vector<vector<int>> &edges)
  {
    // code here
    unordered_map<int, vector<int>> adj;
    for (auto it : edges)
    {
      int u = it[0];
      int v = it[1];

      adj[u].push_back(v);
      adj[v].push_back(u);
    }
    vector<bool> vis(v + 1, false);

    int cnt = 0;

    for (int i = 1; i <= v; i++)
    {
      if (!vis[i])
      {
        vector<int> nodes;

        dfs(i, adj, vis, nodes);

        int sz = nodes.size() - 1;
        bool f = true;

        for (auto it : nodes)
        {
          if (adj[it].size() != sz)
            f = false;
        }

        if (f)
          cnt++;
      }
    }

    return cnt;
  }
};