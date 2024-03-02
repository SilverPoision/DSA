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
  int numProvinces(vector<vector<int>> adj, int V)
  {
    DisJointSet ds(V);
    for (int i = 0; i < V; i++)
    {
      for (int j = 0; j < V; j++)
      {
        if (i != j && adj[i][j] == 1)
        {
          ds.unionByRank(i, j);
        }
      }
    }

    int cnt = 0;
    for (int i = 0; i < V; i++)
    {
      if (ds.parent[i] == i)
        cnt++;
    }

    return cnt;
  }
};