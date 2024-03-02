class Solution
{
public:
  // https://leetcode.com/problems/most-profitable-path-in-a-tree/description/
  vector<int> path;
  void dfs(vector<vector<int>> &adj, vector<int> &v, vector<int> &vis, int src)
  {
    vis[src] = 1;
    v.push_back(src);
    if (src == 0)
    {
      path = v;
      return;
    }
    for (auto x : adj[src])
    {
      if (vis[x] == 0)
      {
        dfs(adj, v, vis, x);
      }
    }
    v.pop_back();
    vis[src] = 0;
  }
  int mostProfitablePath(vector<vector<int>> &e, int b, vector<int> &cost)
  {
    int n = e.size() + 1, ans = INT_MIN;
    vector<vector<int>> adj(n + 1);

    for (int i = 0; i < e.size(); i++)
    {
      adj[e[i][0]].push_back(e[i][1]);
      adj[e[i][1]].push_back(e[i][0]);
    }
    vector<int> vis(n + 1, 0), v;
    dfs(adj, v, vis, b);

    int m = path.size();
    for (int i = 0; i < m / 2; i++)
      cost[path[i]] = 0;
    if (m % 2)
      cost[path[m / 2]] /= 2;

    queue<pair<int, int>> q;
    q.push({0, cost[0]});
    vis = vector<int>(n + 1, 0);

    while (!q.empty())
    {
      int node = q.front().first;
      int val = q.front().second;
      q.pop();

      if (adj[node].size() == 1 && node != 0) // only zero and any ending node can have 1 node because of undirected graph
      {
        ans = max(ans, val);
        continue;
      }
      for (auto x : adj[node])
      {
        if (vis[x] == 0)
        {
          vis[x] = 1;
          q.push({x, val + cost[x]});
        }
      }
    }
    return ans;
  }
};