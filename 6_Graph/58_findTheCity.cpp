class Solution
{
public:
  // https://leetcode.com/problems/find-the-city-with-the-smallest-number-of-neighbors-at-a-threshold-distance/
  void dijkstra(int i, vector<int> &dist, map<int, vector<vector<int>>> &adj)
  {
    dist[i] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
    q.push({0, i});

    while (!q.empty())
    {
      auto front = q.top();
      int node = front.second;
      int w = front.first;
      q.pop();

      for (auto it : adj[node])
      {
        int wt = it[1];
        int v = it[0];
        if (dist[v] > w + wt)
        {
          dist[v] = w + wt;
          q.push({w + wt, v});
        }
      }
    }
  }
  int findTheCity(int n, vector<vector<int>> &edges, int dt)
  {
    map<int, vector<vector<int>>> adj;

    for (auto it : edges)
    {
      adj[it[0]].push_back({it[1], it[2]});
      adj[it[1]].push_back({it[0], it[2]});
    }

    vector<vector<int>> dists(n);

    for (int i = 0; i < n; i++)
    {
      vector<int> dist(n, 1e9);
      dijkstra(i, dist, adj);
      dists[i] = dist;
    }

    int min = 1e9;
    int node = -1;

    for (int i = 0; i < n; i++)
    {
      int cnt = 0;
      for (int j = 0; j < n; j++)
      {
        if (dists[i][j] <= dt)
        {
          cnt++;
        }
      }
      if (cnt <= min)
      {
        min = cnt;
        node = i;
      }
    }

    return node;
  }
};