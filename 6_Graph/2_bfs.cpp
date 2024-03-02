#include <bits/stdc++.h>

void bfs(unordered_map<int, set<int>> &adj, vector<int> &ans, unordered_map<int, bool> &visited, int i)
{
  queue<int> qu;
  qu.push(i);
  visited[i] = true;

  while (!qu.empty())
  {
    int frontNode = qu.front();
    qu.pop();
    ans.push_back(frontNode);

    for (auto j : adj[frontNode])
    {
      if (!visited[j])
      {
        qu.push(j);
        visited[j] = true;
      }
    }
  }
}

vector<int> BFS(int vertex, vector<pair<int, int>> edges)
{
  unordered_map<int, set<int>> adj;
  unordered_map<int, bool> visited;
  vector<int> ans;

  for (int i = 0; i < edges.size(); i++)
  {
    adj[edges[i].first].insert(edges[i].second);
    adj[edges[i].second].insert(edges[i].first);
  }

  for (int i = 0; i < vertex; i++)
  {
    if (!visited[i])
    {
      bfs(adj, ans, visited, i);
    }
  }
  return ans;
}