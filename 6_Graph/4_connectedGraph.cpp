#include <bits/stdc++.h>
using namespace std;
#define n 5

// A utility function to add an edge in an
// undirected graph.
void addEdge(map<int, vector<int>> &adj, int u, int v)
{
  adj[u].push_back(v);
}

void print(map<int, vector<int>> adj)
{
  for (auto it : adj)
  {
    cout << it.first << ": ";
    for (auto it2 : it.second)
    {
      cout << it2 << " ";
    }
    cout << endl;
  }
}

void dfs(int node, vector<bool> &visited, map<int, vector<int>> adj)
{
  visited[node] = true;

  for (auto it : adj[node])
  {
    if (!visited[it])
    {
      dfs(it, visited, adj);
    }
  }
}

bool checkConnected(map<int, vector<int>> adj)
{
  for (int i = 0; i < n; i++)
  {
    vector<bool> visited(n, false);
    dfs(i, visited, adj);

    for (auto it : visited)
    {
      if (!it)
      {
        return false;
      }
    }
  }
  return true;
}

// Driver code
int main()
{

  map<int, vector<int>> adj;

  // Vertex numbers should be from 0 to 4.
  addEdge(adj, 0, 1);
  addEdge(adj, 1, 2);
  addEdge(adj, 2, 3);
  addEdge(adj, 3, 0);
  addEdge(adj, 2, 4);
  addEdge(adj, 4, 2);
  // print(adj);

  checkConnected(adj) ? cout << "Yes\n" : cout << "No\n";

  return 0;
}

// No of provinces
class Solution
{
public:
  void dfs(unordered_map<int, vector<int>> &adj, int node, vector<bool> &vis)
  {
    vis[node] = true;

    for (auto it : adj[node])
    {
      if (!vis[it])
      {
        dfs(adj, it, vis);
      }
    }
  }
  int numProvinces(vector<vector<int>> adj, int V)
  {
    unordered_map<int, vector<int>> m;
    for (int i = 0; i < adj.size(); i++)
    {
      for (int j = 0; j < adj.size(); j++)
      {
        if (i != j && adj[i][j] == 1)
        {
          m[i].push_back(j);
          m[j].push_back(i);
        }
      }
    }
    vector<bool> vis(V, false);
    int cnt = 0;

    for (int i = 0; i < V; i++)
    {
      if (!vis[i])
      {
        cnt++;
        dfs(m, i, vis);
      }
    }
    return cnt;
  }
};