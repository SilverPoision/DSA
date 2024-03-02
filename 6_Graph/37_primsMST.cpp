class Solution
{
public:
  // Function to find sum of weights of edges of the Minimum Spanning Tree.
  int spanningTree(int V, vector<vector<int>> adj[])
  {
    vector<bool> vis(V, false);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
    q.push({0, 0});

    int sum = 0;
    while (!q.empty())
    {
      auto front = q.top();
      q.pop();
      int node = front.second;
      int w = front.first;

      if (vis[node])
        continue;
      vis[node] = true;
      sum += w;

      for (auto it : adj[node])
      {
        int v = it[0];
        int wt = it[1];
        if (!vis[v])
        {
          q.push({wt, v});
        }
      }
    }

    return sum;
  }
};