class DisjointSet
{
public:
  vector<int> parent, rank, size;
  DisjointSet(int n)
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

// https://takeuforward.org/data-structure/most-stones-removed-with-same-row-or-column-dsu-g-53/

class Solution
{
public:
  int removeStones(vector<vector<int>> &stones)
  {
    // getting the dimension of the grid
    int n = stones.size();
    int maxRow = 0;
    int maxCol = 0;
    for (auto it : stones)
    {
      maxRow = max(maxRow, it[0]);
      maxCol = max(maxCol, it[1]);
    }

    DisjointSet ds(maxRow + maxCol + 1);
    unordered_map<int, int> stoneNodes;
    for (auto it : stones)
    {
      int row = it[0];
      int col = it[1] + maxRow + 1; // treating col as row + col ind

      ds.unionBySize(row, col);
      stoneNodes[row] = 1;
      stoneNodes[col] = 1;
    }

    int cnt = 0;
    for (auto it : stoneNodes)
    {
      if (ds.findUPar(it.first) == it.first)
      {
        cnt++;
      }
    }

    return n - cnt;
  }
};