class Solution
{
public:
  // https://leetcode.com/problems/find-the-safest-path-in-a-grid/description/
  vector<int> row = {0, 0, -1, 1};
  vector<int> col = {-1, 1, 0, 0};
  typedef pair<int, pair<int, int>> pii;

  bool isSafe(int r, int c, int n)
  {
    return r < n && r >= 0 && c < n && c >= 0;
  }

  int maximumSafenessFactor(vector<vector<int>> &grid)
  {
    int n = grid.size();

    if (grid[0][0] == 1 || grid[n - 1][n - 1] == 1)
      return 0;

    queue<pair<int, int>> q;
    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < n; j++)
      {
        if (grid[i][j] == 1)
        {
          q.push({i, j});
          grid[i][j] = 0;
        }
        else
        {
          grid[i][j] = -1;
        }
      }
    }

    int len = 1;
    while (!q.empty())
    {
      int sz = q.size();
      while (sz--)
      {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for (int k = 0; k < 4; k++)
        {
          int r = x + row[k];
          int c = y + col[k];

          if (isSafe(r, c, n) && grid[r][c] == -1)
          {
            grid[r][c] = len;
            q.push({r, c});
          }
        }
      }
      len++;
    }

    priority_queue<pii> pq;

    pq.push({grid[0][0], {0, 0}});
    grid[0][0] = -1;

    while (!pq.empty())
    {
      auto top = pq.top();

      int sFact = top.first;

      int x = top.second.first;
      int y = top.second.second;
      pq.pop();

      if (x == n - 1 && y == n - 1)
        return sFact;

      for (int k = 0; k < 4; k++)
      {
        int r = x + row[k];
        int c = y + col[k];

        if (isSafe(r, c, n) && grid[r][c] != -1)
        {
          pq.push({min(sFact, grid[r][c]), {r, c}});
          grid[r][c] = -1;
        }
      }
    }

    return -1;
  }
};