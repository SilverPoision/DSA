class Solution
{
public:
  // https://leetcode.com/problems/minimum-time-to-visit-disappearing-nodes/description/
  // https://www.youtube.com/watch?v=ssABQ7WXSOM&list=WL&index=4&t=68s
  vector<int> dijkstra(int V, unordered_map<int, vector<pair<int, int>>> &adj, int S, vector<int> &dis)
  {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
    q.push({0, S});
    vector<int> dist(V, -1);

    while (!q.empty())
    {
      int node = q.top().second;
      int wt = q.top().first;
      q.pop();
      if (dist[node] != -1)
        continue;
      dist[node] = wt;

      for (auto [v, w] : adj[node])
      {
        if (dist[v] == -1 && wt + w < dis[v])
        {
          q.push({wt + w, v});
        }
      }
    }

    return dist;
  }
  vector<int> minimumTime(int n, vector<vector<int>> &edges, vector<int> &dis)
  {
    unordered_map<int, vector<pair<int, int>>> adj;

    for (auto it : edges)
    {
      int u = it[0];
      int v = it[1];
      int w = it[2];
      adj[u].push_back({v, w});
      adj[v].push_back({u, w});
    }

    return dijkstra(n, adj, 0, dis);
  }
};
