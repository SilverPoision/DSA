class Solution
{
public:
  int findCheapestPrice(int n, vector<vector<int>> &flights, int src, int dst, int k)
  {
    if (src == dst)
      return -1;

    vector<vector<pair<int, int>>> adj(n);

    for (auto it : flights)
    {
      int n1 = it[0];
      int n2 = it[1];
      int dist = it[2];
      adj[n1].push_back({n2, dist});
    }

    queue<pair<int, pair<int, int>>> q; // the increase is constant thats why we dont use a min heap
    // k will always be minimal in the front

    vector<int> dist(n, 1e9);
    dist[src] = 0;
    q.push({0, {src, 0}});

    while (!q.empty())
    {
      auto it = q.front();
      int d = it.second.second;
      int node = it.second.first;
      int step = it.first;
      q.pop();

      if (k < step)
        continue;

      for (auto it : adj[node])
      {
        int v = it.first;
        int w = it.second;
        if (dist[v] > d + w && step <= k)
        {
          dist[v] = d + w;
          q.push({step + 1, {v, dist[v]}});
        }
      }
    }
    if (dist[dst] == 1e9)
      return -1;
    else
      return dist[dst];
  }
};