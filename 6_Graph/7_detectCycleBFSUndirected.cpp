#include <bits/stdc++.h>

bool isCyclic(int node, map<int, bool> &visited, map<int, int> &parent,
              map<int, vector<int>> adj)
{
  queue<int> qu;
  parent[node] = -1;
  visited[node] = true;
  qu.push(node);

  while (!qu.empty())
  {
    int front = qu.front();
    qu.pop();

    for (auto it : adj[front])
    {
      if (visited[it] && it != parent[front])
      {
        return true;
      }
      else if (!visited[it])
      {
        parent[it] = front;
        visited[it] = true;
        qu.push(it);
      }
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
  map<int, int> parent;
  for (int i = 0; i < n; i++)
  {
    if (!visited[i])
    {
      bool cycle = isCyclic(i, visited, parent, adj);
      if (cycle)
      {
        return "Yes";
      }
    }
  }
  return "No";
}
