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
  bool isValid(int r, int c, int n, int m)
  {
    return r >= 0 && r < n && c >= 0 && c < m;
  }
  vector<int> numOfIslands(int n, int m, vector<vector<int>> &operators)
  {
    DisJointSet ds(n * m);
    int cnt = 0;
    vector<int> ans;
    vector<vector<int>> vis(n, vector<int>(m, 0));

    for (auto it : operators)
    {
      int row = it[0];
      int col = it[1];

      if (vis[row][col] == 1)
      {
        ans.push_back(cnt);
        continue;
      }
      vis[row][col] = 1;
      cnt++;

      int dr[] = {1, -1, 0, 0};
      int dc[] = {0, 0, -1, 1};

      for (int ind = 0; ind < 4; ind++)
      {
        int r = row + dr[ind];
        int c = col + dc[ind];

        if (isValid(r, c, n, m))
        {
          if (vis[r][c] == 1)
          {
            int u = row * m + col; // to get the number.
            int v = r * m + c;
            if (ds.findUPar(u) != ds.findUPar(v))
            {
              cnt--;
              ds.unionByRank(u, v);
            }
          }
        }
      }
      ans.push_back(cnt);
    }
    return ans;
  }
};