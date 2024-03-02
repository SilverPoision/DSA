#include <bits/stdc++.h>

int minTimeToRot(vector<vector<int>> &grid, int n, int m)
{
  int rowNbr[] = {0, 0, 1, -1};
  int colNbr[] = {1, -1, 0, 0};

  queue<pair<int, int>> q;
  int minCount = 0;
  int oranges = 0;
  int quBfsCount = 0;

  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      if (grid[i][j] != 0)
      {
        oranges++;
      }
      if (grid[i][j] == 2)
      {
        q.push({i, j});
      }
    }
  }

  while (!q.empty())
  {
    int k = q.size();
    quBfsCount += k;
    while (k--)
    {
      auto top = q.front();
      q.pop();
      for (int o = 0; o < 4; o++)
      {
        int f = top.first + rowNbr[o];
        int s = top.second + colNbr[o];
        if ((f >= 0 && s >= 0 && f < n && s < m && grid[f][s] == 1))
        {
          grid[f][s] = 2;
          q.push({f, s});
        }
      }
    }
    if (!q.empty())
      minCount++;
  }

  return (oranges == quBfsCount ? minCount : -1);
}