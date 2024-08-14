class Solution
{
public:
  // https://leetcode.com/problems/regions-cut-by-slashes/description/?envType=daily-question&envId=2024-08-10
  void dfs(vector<vector<int>> &mat, int i, int j)
  {
    if (i >= mat.size() || i < 0 || j < 0 || j >= mat.size() || mat[i][j] == 1)
      return;

    mat[i][j] = 1;
    dfs(mat, i + 1, j);
    dfs(mat, i - 1, j);
    dfs(mat, i, j + 1);
    dfs(mat, i, j - 1);
  }
  int regionsBySlashes(vector<string> &grid)
  {
    int n = grid.size();

    vector<vector<int>> mat(n * 3, vector<int>(n * 3, 0));

    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < n; j++)
      {
        if (grid[i][j] == '/')
        {
          mat[i * 3][j * 3 + 2] = 1;
          mat[i * 3 + 1][j * 3 + 1] = 1;
          mat[i * 3 + 2][j * 3] = 1;
        }
        else if (grid[i][j] == '\\')
        {
          mat[i * 3][j * 3] = 1;
          mat[i * 3 + 1][j * 3 + 1] = 1;
          mat[i * 3 + 2][j * 3 + 2] = 1;
        }
      }
    }

    int cnt = 0;
    for (int i = 0; i < n * 3; i++)
    {
      for (int j = 0; j < n * 3; j++)
      {
        if (mat[i][j] == 0)
        {
          dfs(mat, i, j);
          cnt++;
        }
      }
    }

    return cnt;
  }
};

// DSU
// https://leetcode.com/problems/regions-cut-by-slashes/solutions/5614771/dcc-10-aug-2024-dsu/
class DisjointSet
{
  List<Integer> parent = new ArrayList<>();
  List<Integer> size = new ArrayList<>();
  int count;

public
  DisjointSet(int n)
  {
    for (int i = 0; i < n; i++)
    {
      parent.add(i);
      size.add(1);
    }
    count = 1;
  }

public
  int find_parent(int node)
  {
    if (node == parent.get(node))
      return node;
    int root = find_parent(parent.get(node));
    parent.set(node, root);
    return root;
  }

public
  void unionBySize(int u, int v)
  {
    int rootU = find_parent(u);
    int rootV = find_parent(v);

    if (rootU == rootV)
    {
      // Increment count if both nodes are already in the same set
      count++;
      return;
    }

    if (size.get(rootU) < size.get(rootV))
    {
      parent.set(rootU, rootV);
      size.set(rootV, size.get(rootV) + size.get(rootU));
    }
    else
    {
      parent.set(rootV, rootU);
      size.set(rootU, size.get(rootU) + size.get(rootV));
    }
  }
}

class Solution
{
public
  int regionsBySlashes(String[] grid)
  {
    int n = grid.length;
    int N = n + 1;
    DisjointSet ds = new DisjointSet(N * N);

    for (int i = 0; i < n + 1; i++)
    {
      for (int j = 0; j < n + 1; j++)
      {
        if (i == 0 || j == 0 || i == n || j == n)
        {
          int col = (n + 1) * i + j;
          if (col != 0)
            ds.unionBySize(0, col);
        }
      }
    }

    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < n; j++)
      {
        if (grid[i].charAt(j) == '/')
        {
          int p1 = (i + 1) * (n + 1) + j;
          int p2 = i * (n + 1) + j + 1;
          ds.unionBySize(p1, p2);
        }
        else if (grid[i].charAt(j) == '\\')
        {
          int p1 = i * (n + 1) + j;
          int p2 = (i + 1) * (n + 1) + j + 1;
          ds.unionBySize(p1, p2);
        }
      }
    }

    return ds.count;
  }
}
