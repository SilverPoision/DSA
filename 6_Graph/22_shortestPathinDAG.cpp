#include <bits/stdc++.h>
using namespace std;

class graph
{
public:
  unordered_map<int, vector<pair<int, int>>> adj;

  void addEdge(int u, int v, int weight)
  {
    pair<int, int> wPair = make_pair(v, weight);
    adj[u].push_back(wPair);
  }

  void printAdj()
  {
    for (auto i : adj)
    {
      cout << i.first << " : ";
      for (auto it : i.second)
      {
        cout << "[" << it.first << ", " << it.second << "]";
      }
      cout << endl;
    }
    cout << endl;
  }

  void dfs(int node, unordered_map<int, bool> &visited, stack<int> &st)
  {
    visited[node] = true;

    for (auto it : adj[node])
    {
      if (!visited[it.first])
      {
        dfs(it.first, visited, st);
      }
    }

    st.push(node);
  }
  void getShortestPath(int src, vector<int> &dist, stack<int> &topo)
  {
    dist[src] = 0;

    while (!topo.empty())
    {
      int top = topo.top();
      topo.pop();
      if (dist[top] != INT_MAX)
      {
        for (auto it : adj[top])
        {
          if (dist[top] + it.second < dist[it.first])
          {
            dist[it.first] = dist[top] + it.second;
          }
        }
      }
    }
  }
};

int main()
{
  graph g;
  g.addEdge(0, 1, 5);
  g.addEdge(0, 2, 3);
  g.addEdge(1, 2, 2);
  g.addEdge(1, 3, 6);
  g.addEdge(2, 3, 7);
  g.addEdge(2, 4, 4);
  g.addEdge(2, 5, 2);
  g.addEdge(3, 4, -1);
  g.addEdge(4, 5, -2);

  g.printAdj();

  int n = 6;
  unordered_map<int, bool> visited;
  stack<int> st;
  for (int i = 0; i < n; i++)
  {
    if (!visited[i])
    {
      g.dfs(i, visited, st);
    }
  }

  int src = 1;
  vector<int> dist(n, INT_MAX);

  g.getShortestPath(src, dist, st);

  cout << "The answer is: ";
  for (auto it : dist)
  {
    if (it == INT_MAX)
    {
      cout << "∞"
           << ",";
    }
    else
    {
      cout << it << ",";
    }
  }

  return 0;
}

// Same
class Solution
{
public:
  void dfs(int node, vector<int> &vis, stack<int> &st, vector<vector<pair<int, int>>> &adj)
  {
    vis[node] = 1;

    for (auto it : adj[node])
    {
      if (!vis[it.first])
      {
        dfs(it.first, vis, st, adj);
      }
    }

    st.push(node);
  }
  vector<int> shortestPath(int N, int M, vector<vector<int>> &edges)
  {
    vector<vector<pair<int, int>>> adj(N);
    vector<int> vis(N, 0);

    for (auto it : edges)
    {
      adj[it[0]].push_back({it[1], it[2]});
    }

    stack<int> st;
    for (int i = 0; i < N; i++)
    {
      if (!vis[i])
      {
        dfs(i, vis, st, adj);
      }
    }

    vector<int> dist(N, 1e9);
    dist[0] = 0;
    while (!st.empty())
    {
      int top = st.top();
      st.pop();

      for (auto it : adj[top])
      {
        int v = it.first;
        int wt = it.second;

        if (dist[v] > dist[top] + wt)
        {
          dist[v] = dist[top] + wt;
        }
      }
    }
    for (int i = 0; i < N; i++)
    {
      if (dist[i] == 1e9)
      {
        dist[i] = -1;
      }
    }
    return dist;
  }
};