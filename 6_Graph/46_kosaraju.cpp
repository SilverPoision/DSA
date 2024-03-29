class Solution
{
private:
  void dfs(int node, vector<int> &vis, stack<int> &st, vector<vector<int>> &adj)
  {
    vis[node] = 1;

    for (auto it : adj[node])
    {
      if (!vis[it])
      {
        dfs(it, vis, st, adj);
      }
    }
    st.push(node);
  };

  void dfsRev(int node, vector<int> &vis, vector<int> adjT[])
  {
    vis[node] = 1;

    for (auto it : adjT[node])
    {
      if (!vis[it])
      {
        dfsRev(it, vis, adjT);
      }
    }
  };

public:
  // Function to find number of strongly connected components in the graph.
  int kosaraju(int V, vector<vector<int>> &adj)
  {
    vector<int> vis(V, 0);
    stack<int> st;
    for (int i = 0; i < V; i++)
    {
      if (!vis[i])
      {
        dfs(i, vis, st, adj);
      }
    }

    vector<int> adjT[V];
    for (int i = 0; i < V; i++)
    {
      vis[i] = 0;
      for (auto it : adj[i])
      {
        adjT[it].push_back(i);
      }
    }

    int cnt = 0;
    while (!st.empty())
    {
      int node = st.top();
      st.pop();

      if (!vis[node])
      {
        cnt++;
        dfsRev(node, vis, adjT);
      }
    }

    return cnt;
  }
};