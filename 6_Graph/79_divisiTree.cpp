class Solution
{
public:
  // https://www.geeksforgeeks.org/problems/divisibility-tree1902/1
  int ans = 0;

  int dfs(int node, unordered_map<int, vector<int>> &adj, vector<bool> &vis)
  {
    vis[node] = true;

    int cnt = 0;

    for (auto it : adj[node])
    {
      if (!vis[it])
      {
        int res = dfs(it, adj, vis);
        if (res % 2 == 0)
          ans++;
        else
          cnt += res;
      }
    }

    return cnt + 1;
  }
  int minimumEdgeRemove(int n, vector<vector<int>> edges)
  {
    // Code here
    vector<bool> vis(n, false);

    unordered_map<int, vector<int>> adj;

    for (auto it : edges)
    {
      int u = it[0];
      int v = it[1];

      adj[u - 1].push_back(v - 1);
      adj[v - 1].push_back(u - 1);
    }

    dfs(0, adj, vis);

    return ans;
  }
};