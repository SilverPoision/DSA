#include <bits/stdc++.h>
using namespace std;

/*
Disjoint set are used to find if two eles are in same component in a graph
they are more frequently used in dynamuc graph, those graphs that change frequently
*/

class DisJointSet
{
public:
  vector<int> parent, rank, size;
  DisJointSet(int n)
  {
    rank.resize(n + 1, 0); // it just says that this compo is bigger than the other not by size not by height but by rank
    parent.resize(n + 1);
    size.resize(n + 1, 1);
    for (int i = 0; i <= n; i++)
    {
      parent[i] = i; // initially everyone is a parent of himself
    }
  }

  int findUPar(int node)
  {
    if (node == parent[node])
      return node;

    return parent[node] = findUPar(parent[node]);
  }

  void unionByRank(int u, int v)
  {
    int ulp_v = findUPar(v); // get Ultimate parent
    int ulp_u = findUPar(u);

    if (ulp_v == ulp_u)
      return;
    if (rank[ulp_v] < rank[ulp_u]) // connevct the smaller with larger one
    {
      parent[ulp_v] = ulp_u;
    }
    else if (rank[ulp_v] > rank[ulp_u])
    {
      parent[ulp_u] = ulp_v;
    }
    else
    {
      parent[ulp_v] = ulp_u;
      rank[ulp_u]++;
    }
  }
  void unionBySize(int u, int v)
  {
    int ulp_v = findUPar(v);
    int ulp_u = findUPar(u);

    if (ulp_v == ulp_u)
      return;
    if (size[ulp_v] < size[ulp_u])
    {
      parent[ulp_v] = ulp_u;
      size[ulp_u] += size[ulp_v];
    }
    else
    {
      parent[ulp_u] = ulp_v;
      size[ulp_v] += size[ulp_u];
    }
  }
};

int main()
{
  DisJointSet ds(7);
  ds.unionBySize(1, 2); // go and connect these two nodes
  ds.unionBySize(2, 3);
  ds.unionBySize(4, 5);
  ds.unionBySize(6, 7);
  ds.unionBySize(5, 6);
  if (ds.findUPar(3) == ds.findUPar(7))
  {
    cout << "Same\n";
  }
  else
  {
    cout << "Not Same\n";
  }
  ds.unionByRank(3, 7);
  if (ds.findUPar(3) == ds.findUPar(7))
  {
    cout << "Same\n";
  }
  else
  {
    cout << "Not Same\n";
  }
  return 0;
}