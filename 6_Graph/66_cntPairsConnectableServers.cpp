class Solution
{
public:
  // https://leetcode.com/problems/count-pairs-of-connectable-servers-in-a-weighted-tree-network/?envType=list&envId=opbzdrut
  int ct, ss;
  unordered_map<int, vector<pair<int, int>>> adj;
  void dfs(int node, int par, int dist)
  {
    if (dist % ss == 0)
      ct++;
    for (auto [ch, d] : adj[node])
    {
      if (ch != par)
        dfs(ch, node, d + dist);
    }
  }

  vector<int> countPairsOfConnectableServers(vector<vector<int>> &edges, int signalSpeed)
  {
    int n = edges.size() + 1;
    ss = signalSpeed;
    for (auto it : edges)
    {
      int u = it[0];
      int v = it[1];
      int w = it[2];
      adj[u].push_back({v, w});
      adj[v].push_back({u, w});
    }

    vector<int> cnt(n, 0);
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
      int sum = 0;
      int ans = 0;
      vector<int> temp;
      for (auto [ch, dis] : adj[i])
      {
        ct = 0;
        dfs(ch, i, dis);
        temp.push_back(ct);
        sum += ct;
      }

      for (auto it : temp)
        ans += (sum - it) * it;
      cnt[i] = ans / 2;
    }

    return cnt;
  }
};