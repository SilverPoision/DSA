class Solution
{
public:
  // https://leetcode.com/problems/sum-of-distances-in-tree/description/
  vector<int> cnt;
  int n;
  long rootCnt;

  int dfsBase(int node, unordered_map<int, vector<int>> &adj, int prev, int steps)
  {
    rootCnt += steps;

    int total_nodes = 1;
    for (auto it : adj[node])
    {
      if (prev != it)
        total_nodes += dfsBase(it, adj, node, steps + 1);
    }

    return cnt[node] = total_nodes;
  }

  void dfs(int node, unordered_map<int, vector<int>> &adj, int prev, vector<int> &res)
  {
    for (auto it : adj[node])
    {
      if (it == prev)
        continue;
      res[it] = res[node] + (n - cnt[it]) - cnt[it];
      dfs(it, adj, node, res);
    }
  }
  vector<int> sumOfDistancesInTree(int n, vector<vector<int>> &edges)
  {
    this->n = n;
    unordered_map<int, vector<int>> adj;
    for (auto it : edges)
    {
      int u = it[0];
      int v = it[1];

      adj[u].push_back(v);
      adj[v].push_back(u);
    }

    rootCnt = 0;
    cnt.resize(n, 0);

    dfsBase(0, adj, -1, 0);

    vector<int> res(n, 0);
    res[0] = rootCnt;

    dfs(0, adj, -1, res);

    return res;
  }
};