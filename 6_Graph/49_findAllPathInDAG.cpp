#include <bits/stdc++.h>
using namespace std;

// Function to perform BFS traversal from the source vertex in the graph to
// determine if the destination vertex is reachable from the source or not
void dfs(int src, int dest, vector<bool> &vis, unordered_map<int, vector<int>> adj, vector<vector<int>> &res, vector<int> &ans)
{
  vis[src] = true;
  ans.push_back(src);
  if (src == dest)
  {
    res.push_back(ans);
  }
  else
  {
    for (auto it : adj[src])
    {
      if (!vis[it])
      {
        dfs(it, dest, vis, adj, res, ans);
      }
    }
  }

  vis[src] = false;
  ans.pop_back();
}

int main()
{
  vector<pair<int, int>> edges = {{0, 1}, {1, 0}, {0, 2}, {0, 3}, {1, 3}, {3, 2}};

  // Number of nodes in the graph (labelled from 0 to N-1)
  int N = 4;
  int src = 1, dest = 2;

  unordered_map<int, vector<int>> adj;

  for (auto it : edges)
  {
    adj[it.first].push_back(it.second);
  }

  vector<bool> vis(N);
  vector<vector<int>> res;
  vector<int> ans;

  dfs(src, dest, vis, adj, res, ans);

  for (auto it : res)
  {
    cout << "[";
    for (auto i : it)
    {
      cout << i << " ";
    }
    cout << "]";
  }

  return 0;
}