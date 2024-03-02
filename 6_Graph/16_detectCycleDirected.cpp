class Solution
{
public:
  // Function to detect cycle in a directed graph.
  bool dfs(int node, vector<int> &vis, vector<int> &dfsvis, vector<int> adj[])
  {
    vis[node] = 1;
    dfsvis[node] = 1;

    for (auto it : adj[node])
    {
      if (vis[it] == 0)
      {
        if (dfs(it, vis, dfsvis, adj) == true)
          return true;
      }
      else if (dfsvis[it] == 1)
      {
        return true;
      }
    }
    dfsvis[node] = 0;
    return false;
  }
  bool isCyclic(int V, vector<int> adj[])
  {
    vector<int> vis(V, 0);
    vector<int> dfsvis(V, 0);

    for (int i = 0; i < V; i++)
    {
      if (vis[i] == 0)
      {
        if (dfs(i, vis, dfsvis, adj) == true)
          return true;
      }
    }

    return false;
  }
};