class Solution
{
public:
  // https://leetcode.com/problems/count-subtrees-with-max-distance-between-cities/
  int getDist(int mask, vector<vector<int>> &dist, int n)
  {
    int nCnt = 0, eCnt = 0, maxDist = 0;
    for (int i = 0; i < n; i++)
    {
      if ((mask & (1 << i)) == 0)
        continue;
      nCnt++;
      for (int j = i + 1; j < n; j++)
      {
        if ((mask & (1 << j)) == 0)
          continue;
        eCnt += dist[i][j] == 1;

        maxDist = max(maxDist, dist[i][j]);
      }
    }

    if (nCnt == eCnt + 1)
    {
      return maxDist;
    }

    return 0;
  }
  vector<int> countSubgraphsForEachDiameter(int n, vector<vector<int>> &edges)
  {
    vector<vector<int>> dist(n, vector<int>(n, 1e9));

    for (auto it : edges)
    {
      int u = it[0];
      int v = it[1];
      dist[u - 1][v - 1] = dist[v - 1][u - 1] = 1;
    }

    for (int k = 0; k < n; k++)
    {
      for (int i = 0; i < n; i++)
      {
        for (int j = 0; j < n; j++)
        {
          dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
        }
      }
    }

    vector<int> ans(n - 1, 0);
    for (int i = 0; i < (1 << n); i++)
    {
      int d = getDist(i, dist, n);
      if (d > 0)
        ans[d - 1]++;
    }

    return ans;
  }
};

class Solution
{
public:
  int getDist(int mask, unordered_map<int, vector<int>> &adj, int n)
  {
    vector<int> cities(n, 1e9);
    int cCnt = 0;
    for (int i = 0; i < n; i++)
    {
      if ((mask & (1 << i)) != 0)
      {
        cities[i] = 1;
        cCnt++;
      }
    }
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
      if (cities[i] == 1)
      {
        auto node = bfs(i, cities, n, adj); // cnt of visited nodes, maxDistance
        if (cCnt > node.first)
          return 0;
        ans = max(ans, node.second);
      }
    }

    return ans;
  }

  pair<int, int> bfs(int src, vector<int> &cities, int n, unordered_map<int, vector<int>> &adj)
  {
    vector<bool> vis(n, false);
    vis[src] = true;
    int visCnt = 1;
    queue<pair<int, int>> q; // node and dist
    q.push({src, 0});

    int maxDist = 0;

    while (!q.empty())
    {
      auto node = q.front();
      q.pop();
      maxDist = node.second;

      for (auto it : adj[node.first])
      {
        if (!vis[it] && cities[it] != 1e9)
        {
          vis[it] = true;
          visCnt++;
          q.push({it, node.second + 1});
        }
      }
    }

    return {visCnt, maxDist};
  }
  vector<int> countSubgraphsForEachDiameter(int n,
                                            vector<vector<int>> &edges)
  {
    unordered_map<int, vector<int>> adj;

    for (auto it : edges)
    {
      int u = it[0];
      int v = it[1];
      adj[u - 1].push_back(v - 1);
      adj[v - 1].push_back(u - 1);
    }

    vector<int> ans(n - 1, 0);
    for (int i = 0; i < (1 << n); i++)
    {
      int d = getDist(i, adj, n);
      if (d > 0)
        ans[d - 1]++;
    }

    return ans;
  }
};