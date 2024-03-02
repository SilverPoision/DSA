#include <bits/stdc++.h>

void dfs(int node, map<int, vector<int>> adj, map<int, bool> &visited, vector<int> &comp)
{
  comp.push_back(node);
  visited[node] = true;

  for (auto i : adj[node])
  {
    if (!visited[i])
    {
      dfs(i, adj, visited, comp);
    }
  }
}

vector<vector<int>> depthFirstSearch(int V, int E, vector<vector<int>> &edges)
{
  map<int, vector<int>> adj;
  for (auto it : edges)
  {
    adj[it[0]].push_back(it[1]);
    adj[it[1]].push_back(it[0]);
  }

  vector<vector<int>> ans;
  map<int, bool> visited;
  for (int i = 0; i < V; i++)
  {
    if (!visited[i])
    {
      vector<int> comp;
      dfs(i, adj, visited, comp);
      ans.push_back(comp);
    }
  }
  return ans;
}