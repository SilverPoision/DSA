#include <bits/stdc++.h>

int rowNbr[] = {0, 0, 1, -1};
int colNbr[] = {1, -1, 0, 0};

bool dfs(int i, int j, vector<vector<char>> &board, string word, int n, int m)
{
  if (word.length() == 0)
  {
    return true;
  }
  char ch = board[i][j];
  board[i][j] = '.';
  for (int x = 0; x < 4; x++)
  {
    int nI = i + rowNbr[x];
    int nJ = j + colNbr[x];
    if ((nI < n && nJ < m && nI >= 0 && nJ >= 0 && board[nI][nJ] == word[0]))
    {
      if (dfs(nI, nJ, board, word.substr(1), n, m))
        return true;
    }
  }
  board[i][j] = ch;
  return false;
}

bool present(vector<vector<char>> &board, string word, int n, int m)
{

  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      if (board[i][j] == word[0])
      {
        if (dfs(i, j, board, word.substr(1), n, m))
        {
          return true;
        }
      }
    }
  }
  return false;
}