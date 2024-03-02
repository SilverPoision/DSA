#include <bits/stdc++.h>

int minDiceThrowToLastCell(int **board, int n)
{
  reverse(board, board + n);
  vector<vector<int>> vis(n, vector<int>(n, 0));
  queue<int> q;
  q.push(1);
  int c = 0;
  vis[0][0] = true;

  while (!q.empty())
  {
    int size = q.size();
    while (size--)
    {
      int square = q.front();
      q.pop();
      if (square == n * n)
      {
        return c;
      }
      for (int i = 1; i <= 6; i++)
      {
        int nextSq = square + i;
        if (nextSq > n * n)
        {
          break;
        }
        int r = (nextSq - 1) / n;
        int c = (nextSq - 1) % n;
        if (r % 2)
          c = n - c - 1;

        if (vis[r][c])
        {
          continue;
        }

        vis[r][c] = true;

        if (board[r][c] != -1)
        {
          nextSq = board[r][c];
          q.push(nextSq);
        }
        else
        {
          q.push(nextSq);
        }
      }
    }
    c++;
  }
  return -1;
}