class DisJointSet
{
public:
  vector<int> parent, rank, size;
  DisJointSet(int n)
  {
    rank.resize(n + 1, 0);
    parent.resize(n + 1);
    size.resize(n + 1, 1);
    for (int i = 0; i <= n; i++)
    {
      parent[i] = i;
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
    int ulp_v = findUPar(v);
    int ulp_u = findUPar(u);

    if (ulp_v == ulp_u)
      return;
    if (rank[ulp_v] < rank[ulp_u])
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

class Solution
{
public:
  // Function to find sum of weights of edges of the Minimum Spanning Tree.
  int spanningTree(int V, vector<vector<int>> adj[])
  {
    vector<pair<int, pair<int, int>>> edges;

    for (int i = 0; i < V; i++)
    {
      for (auto it : adj[i])
      {
        int u = it[0];
        int w = it[1];
        int node = i;

        edges.push_back({w, {u, node}});
      }
    }

    sort(edges.begin(), edges.end());
    DisJointSet ds(V);

    int sum = 0;
    for (auto it : edges)
    {
      int u = it.second.first;
      int v = it.second.second;
      int w = it.first;

      int uP = ds.findUPar(u);
      int vP = ds.findUPar(v);

      if (uP != vP)
      {
        ds.unionByRank(u, v);
        sum += w;
      }
    }
    return sum;
  }
};