class Solution
{
public:
  // https://leetcode.com/problems/find-edges-in-shortest-paths/description/
  typedef pair<int, int> pii;
  typedef long long ll;
  vector<ll> minPath(int src, unordered_map<int, vector<vector<int>>> &adj, int n)
  {
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({0, src});
    vector<ll> path(n, 1e9);

    while (!pq.empty())
    {
      auto [w, node] = pq.top();
      pq.pop();

      if (path[node] != 1e9)
        continue;

      path[node] = w;

      for (auto it : adj[node])
      {
        int u = it[0];
        int wt = it[1];
        if (path[u] == 1e9)
        {
          pq.push({wt + w, u});
        }
      }
    }

    return path;
  }
  vector<bool> findAnswer(int n, vector<vector<int>> &edges)
  {
    unordered_map<int, vector<vector<int>>> adj;

    for (auto it : edges)
    {
      int u = it[0];
      int v = it[1];
      int w = it[2];

      adj[u].push_back({v, w});
      adj[v].push_back({u, w});
    }

    vector<ll> sDist = minPath(0, adj, n);
    vector<ll> distS = minPath(n - 1, adj, n);

    ll shortestDist = sDist[n - 1];

    vector<bool> ans(edges.size(), false);
    for (int i = 0; i < edges.size(); i++)
    {
      int u = edges[i][0];
      int v = edges[i][1];
      int w = edges[i][2];
      if ((sDist[u] + (ll)w + distS[v]) == shortestDist)
      {
        ans[i] = true;
      }
      if ((sDist[v] + (ll)w + distS[u]) == shortestDist)
      {
        ans[i] = true;
      }
    }

    return ans;
  }
};