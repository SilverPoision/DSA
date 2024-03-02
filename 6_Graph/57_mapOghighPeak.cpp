class Solution
{
public:
  // https://leetcode.com/problems/map-of-highest-peak/
  vector<vector<int>> highestPeak(vector<vector<int>> &mat)
  {
    int n = mat.size();
    int m = mat[0].size();

    vector<int> row = {1, -1, 0, 0};
    vector<int> col = {0, 0, 1, -1};
    vector<vector<int>> ans(n, vector<int>(m, -1));

    queue<pair<int, int>> q;

    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < m; j++)
      {
        if (mat[i][j] == 1)
        {
          q.push({i, j});
          ans[i][j] = 0;
        }
      }
    }

    while (!q.empty())
    {
      auto front = q.front();
      int x = front.first;
      int y = front.second;
      int v = ans[x][y];
      q.pop();

      for (int k = 0; k < 4; k++)
      {
        int r = x + row[k];
        int c = y + col[k];
        if (r >= 0 && c >= 0 && r < n && c < m)
        {
          if (ans[r][c] == -1)
          {
            ans[r][c] = v + 1;
            q.push({r, c});
          }
        }
      }
    }

    return ans;
  }
};