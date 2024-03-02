class Solution
{
public:
  vector<int> shortestPath(int n, int m, vector<vector<int>> &edges)
  {
    vector<vector<pair<int, int>>> adj(n + 1);
    for (auto it : edges)
    {
      int node1 = it[0];
      int node2 = it[1];
      int wt = it[2];
      adj[node1].push_back({node2, wt});
      adj[node2].push_back({node1, wt});
    }
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
    q.push({0, 1});
    vector<int> dist(n + 1, 1e9);
    vector<int> parent(n + 1);
    for (int i = 0; i <= n; i++)
      parent[i] = i;
    dist[1] = 0;

    while (!q.empty())
    {
      int node = q.top().second;
      int wt = q.top().first;
      q.pop();

      for (auto it : adj[node])
      {
        int v = it.first;
        int w = it.second;
        if (w + wt < dist[v])
        {
          dist[v] = wt + w;
          parent[v] = node;
          q.push({dist[v], v});
        }
      }
    }

    if (dist[n] == 1e9)
      return {-1};

    vector<int> ans;
    int src = n;
    while (src != parent[src])
    {
      ans.push_back(src);
      src = parent[src];
    }
    ans.push_back(1);
    reverse(ans.begin(), ans.end());

    return ans;
  }
};