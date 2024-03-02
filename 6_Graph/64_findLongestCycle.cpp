class Solution
{
public:
  // exact same but diff runtime because of lambda exp
  // https://leetcode.com/problems/longest-cycle-in-a-graph/
  int ans = -1;

  void dfs(int node, vector<int> &edges, vector<int> &vis, vector<int> &pathvis, vector<int> &count)
  {
    if (node != -1)
    {

      vis[node] = 1;
      pathvis[node] = 1;

      int adjnode = edges[node];

      if (adjnode != -1 && !vis[adjnode])
      {
        count[adjnode] = count[node] + 1;
        dfs(adjnode, edges, vis, pathvis, count);
      }
      else if (adjnode != -1 && pathvis[adjnode] == 1)
      { // cycle found
        ans = max(ans, abs(count[node] - count[adjnode]) + 1);
      }

      pathvis[node] = 0;
    }
  }

  int longestCycle(vector<int> &edges)
  { // don't need adj list
    int n = edges.size();
    vector<int> vis(n, 0);
    vector<int> pathvis(n, 0);
    vector<int> count(n, 1);

    for (int i = 0; i < n; i++)
    {
      if (!vis[i])
      {
        dfs(i, edges, vis, pathvis, count);
      }
    }

    return ans;
  }
};

class Solution
{
public:
  int longestCycle(vector<int> &edges)
  {
    int n = edges.size();
    vector<int> cnt(n, 1);
    vector<bool> vis(n, false), dfsVis(n, false);
    int res = -1;

    function<void(int)> dfs = [&](int u)
    {
      if (u != -1)
      {
        vis[u] = true;
        dfsVis[u] = true;

        int v = edges[u];
        if (v != -1 && !vis[v])
        {
          cnt[v] = cnt[u] + 1;
          dfs(v);
        }
        else if (v != -1 && dfsVis[v])
        {
          res = max(res, cnt[u] - cnt[v] + 1);
        }

        dfsVis[u] = false;
      }
    };

    for (int i = 0; i < n; i++)
    {
      if (!vis[i])
      {
        dfs(i);
      }
    }

    return res;
  }
};