#include <bits/stdc++.h>

bool isCyclic(int node, map<int, bool> &visited, map<int, vector<int>> adj, int parent)
{
  visited[node] = true;

  for (auto it : adj[node])
  {
    if (!visited[it])
    {
      if (isCyclic(it, visited, adj, node))
      {
        return true;
      }
    }
    else if (it != parent)
    {
      return true;
    }
  }
  return false;
}

string cycleDetection(vector<vector<int>> &edges, int n, int m)
{
  map<int, vector<int>> adj;
  for (auto it : edges)
  {
    adj[it[0]].push_back(it[1]);
    adj[it[1]].push_back(it[0]);
  }

  map<int, bool> visited;
  for (int i = 0; i < n; i++)
  {
    if (!visited[i])
    {
      if (isCyclic(i, visited, adj, -1))
      {
        return "Yes";
      }
    }
  }
  return "No";
}
