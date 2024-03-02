#include <bits/stdc++.h>
// It is used to find the shortest path with -ve weights and doesn't work
//  on negative cycle graphs and can also be used to detect -ve cycle graph
class Solution
{
public:
  /*  Function to implement Bellman Ford
   *   edges: vector of vectors which represents the graph
   *   S: source vertex to start traversing graph with
   *   V: number of vertices
   */
  vector<int> bellman_ford(int V, vector<vector<int>> &edges, int S)
  {
    vector<int> dist(V, 1e8);
    dist[S] = 0;
    for (int i = 0; i < V - 1; i++)
    {
      for (auto it : edges)
      {
        int u = it[0];
        int v = it[1];
        int w = it[2];
        if (dist[u] != 1e9 && dist[u] + w < dist[v])
        {
          dist[v] = dist[u] + w;
        }
      }
    }

    for (auto it : edges)
    {
      int u = it[0];
      int v = it[1];
      int w = it[2];
      if (dist[u] != 1e9 && dist[u] + w < dist[v])
      {
        return {-1};
      }
    }

    return dist;
  }
};