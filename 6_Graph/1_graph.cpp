#include <bits/stdc++.h>
using namespace std;

template <typename T>
class graph
{
public:
  unordered_map<T, vector<T>> adj;

  void addEdge(T u, T v, bool directed)
  {
    adj[u].push_back(v);

    if (directed == 0)
    {
      adj[v].push_back(u);
    }
  }

  void printAdj()
  {
    for (auto it : adj)
    {
      cout << it.first << " -> ";
      for (auto it2 : it.second)
      {
        cout << it2 << ", ";
      }
      cout << endl;
    }
  }
};

int main()
{
  graph<int> g;

  int m;

  cin >> m;

  for (int i = 0; i < m; i++)
  {
    int u, v;
    cin >> u >> v;
    g.addEdge(u, v, 0);
  }

  g.printAdj();
  return 0;
}