#include <bits/stdc++.h>

vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)
{
  unordered_map<int, vector<int>> adj;
  for (auto it : edges)
  {
    adj[it[0]].push_back(it[1]);
  }

  vector<int> indegree(v);
  for (auto it : adj)
  {
    for (auto j : it.second)
    {
      indegree[j]++;
    }
  }

  queue<int> q;
  for (int i = 0; i < v; i++)
  {
    if (indegree[i] == 0)
    {
      q.push(i);
    }
  }

  vector<int> ans;
  while (!q.empty())
  {
    int front = q.front();
    q.pop();
    ans.push_back(front);

    for (auto it : adj[front])
    {
      indegree[it]--;
      if (indegree[it] == 0)
      {
        q.push(it);
      }
    }
  }
  return ans;
}