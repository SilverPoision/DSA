#include <bits/stdc++.h>

int detectCycleInDirectedGraph(int n, vector<pair<int, int>> &edges)
{
  unordered_map<int, vector<int>> adj;
  for (auto it : edges)
  {
    adj[(it.first - 1)].push_back((it.second - 1));
  }

  vector<int> indegree(n);
  for (auto it : adj)
  {
    for (auto j : it.second)
    {
      indegree[j]++;
    }
  }

  queue<int> q;
  for (int i = 0; i < n; i++)
  {
    if (indegree[i] == 0)
    {
      q.push(i);
    }
  }

  int cnt = 0;
  while (!q.empty())
  {
    int front = q.front();
    q.pop();
    cnt++;

    for (auto it : adj[front])
    {
      indegree[it]--;
      if (indegree[it] == 0)
      {
        q.push(it);
      }
    }
  }
  return (cnt != n); // if there will be a cycle present the indegree will not become 0 for some elemenet while the algo is running
}