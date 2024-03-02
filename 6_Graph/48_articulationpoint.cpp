// The node when removed increase the no of components in the graph.
class Solution
{
  // https://www.youtube.com/watch?v=j1QDfU21iZk
  int timer;

  void dfs(int node, int parent, vector<int> &vis, int tin[], int low[], vector<int> &mark, vector<int> adj[])
  {
    vis[node] = 1;
    low[node] = tin[node] = timer;
    timer++;
    int child = 0;
    for (auto it : adj[node])
    {
      if (it == parent)
        continue;
      if (!vis[it])
      {
        dfs(it, node, vis, tin, low, mark, adj);
        low[node] = min(low[node], low[it]);
        child++;
        if (low[it] >= tin[node] && parent != -1)
        {
          mark[node] = 1;
        }
      }
      else
      {
        low[node] = min(low[node], tin[it]); // because you cannout access the prior nodes because you are removing this node hyothetically so you take the time of insertion
      }
    }

    if (child > 1 && parent == -1)
    {
      mark[node] = 1;
    }
  }

public:
  vector<int> articulationPoints(int V, vector<int> adj[])
  {
    vector<int> vis(V, 0);
    int tin[V];
    int low[V];
    vector<int> mark(V, 0);

    for (int i = 0; i < V; i++)
    {
      if (!vis[i])
      {
        dfs(i, -1, vis, tin, low, mark, adj);
      }
    }

    vector<int> ans;
    for (int i = 0; i < V; i++)
    {
      if (mark[i] == 1)
      {
        ans.push_back(i);
      }
    }
    if (ans.size() == 0)
      return {-1};
    return ans;
  }
};