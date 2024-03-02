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
  bool isValid(int r, int c, int n)
  {
    return r >= 0 && r < n && c >= 0 && c < n;
  }

public:
  int MaxConnection(vector<vector<int>> &grid)
  {
    int n = grid.size();
    DisJointSet ds(n * n);
    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < n; j++)
      {
        if (grid[i][j] == 0)
          continue;
        int dr[] = {1, -1, 0, 0};
        int dc[] = {0, 0, 1, -1};

        for (int ind = 0; ind < 4; ind++)
        {
          int r = i + dr[ind];
          int c = j + dc[ind];

          if (isValid(r, c, n) && grid[r][c] == 1)
          {
            int nodeNo = i * n + j;
            int adjNode = r * n + c;
            ds.unionBySize(nodeNo, adjNode);
          }
        }
      }
    }

    int mx = 0;
    for (int row = 0; row < n; row++)
    {
      for (int col = 0; col < n; col++)
      {
        if (grid[row][col] == 1)
          continue;

        int dr[] = {1, -1, 0, 0};
        int dc[] = {0, 0, 1, -1};

        set<int> s;

        for (int ind = 0; ind < 4; ind++)
        {
          int r = row + dr[ind];
          int c = col + dc[ind];

          if (isValid(r, c, n))
          {
            if (grid[r][c] == 1)
            {
              s.insert(ds.findUPar(r * n + c));
            }
          }
        }
        int cnt = 0;
        for (auto it : s)
        {
          cnt += ds.size[it];
        }
        mx = max(mx, cnt + 1);
      }
    }

    for (int i = 0; i < n * n; i++)
    {
      mx = max(mx, ds.size[ds.findUPar(i)]);
    }

    return mx;
  }
};