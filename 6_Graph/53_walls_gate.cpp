#include <bits/stdc++.h>

void isSafe(int i, int j, int n, int m, vector<vector<int>> &a, vector<vector<int>> &vis, queue<pair<int, int>> &q)
{
  if (i < 0 || j < 0 || i == n || j == m || a[i][j] == -1 || vis[i][j] == 1)
    return;

  vis[i][j] = 1;
  q.push({i, j});
}

vector<vector<int>> wallsAndGates(vector<vector<int>> &a, int n, int m)
{
  vector<vector<int>> vis(n, vector<int>(m, 0));
  queue<pair<int, int>> q;

  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      if (a[i][j] == 0)
      {
        q.push({i, j});
        vis[i][j] = 1;
      }
    }
  }
  int dist = 0;
  while (!q.empty())
  {
    int k = q.size();
    while (k--)
    {
      int Ni = q.front().first;
      int Nj = q.front().second;
      q.pop();

      a[Ni][Nj] = dist;
      isSafe((Ni), (Nj + 1), n, m, a, vis, q);
      isSafe((Ni), (Nj - 1), n, m, a, vis, q);
      isSafe((Ni + 1), (Nj), n, m, a, vis, q);
      isSafe((Ni - 1), (Nj), n, m, a, vis, q);
    }
    dist++;
  }
  return a;
}