#include <bits/stdc++.h>

void topoSort(int node, unordered_map<int, vector<int>> adj, unordered_map<int, bool> &visited, stack<int> &st)
{
  visited[node] = true;

  for (auto it : adj[node])
  {
    if (!visited[it])
    {
      topoSort(it, adj, visited, st);
    }
  }
  st.push(node);
}

vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)
{
  unordered_map<int, vector<int>> adj;
  for (auto it : edges)
  {
    int u = it[0];
    int v = it[1];

    adj[u].push_back(v);
  }

  unordered_map<int, bool> visited;
  stack<int> st;
  for (int i = 0; i < v; i++)
  {
    if (!visited[i])
    {
      topoSort(i, adj, visited, st);
    }
  }

  vector<int> ans;
  while (!st.empty())
  {
    int top = st.top();
    st.pop();
    ans.push_back(top);
  }

  return ans;
}