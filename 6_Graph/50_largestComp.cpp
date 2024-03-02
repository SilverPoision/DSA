#include <bits/stdc++.h>
using namespace std;
#define ROW 4
#define COL 5

int rowNbr[] = {-1, -1, -1, 0, 0, 1, 1, 1};
int colNbr[] = {-1, 0, 1, -1, 1, -1, 0, 1};

// A function to check if a given cell (row, col)
// can be included in DFS
int isSafe(int M[][COL], int row, int col,
           bool visited[][COL])
{
  // row number is in range, column number is in
  // range and value is 1 and not yet visited
  return (row >= 0) && (row < ROW) &&
         (col >= 0) && (col < COL) &&
         (M[row][col] && !visited[row][col]);
}

void dfs(int i, int j, int M[][COL], bool vis[][COL], int *count)
{
  for (int k = 0; k < 8; k++)
  {
    if (isSafe(M, (i + rowNbr[k]), (j + colNbr[k]), vis))
    {
      vis[(i + rowNbr[k])][(j + colNbr[k])] = 1;
      (*count)++;
      dfs((i + rowNbr[k]), (j + colNbr[k]), M, vis, count);
    }
  }
}

// The main function that returns largest  length region
// of a given boolean 2D matrix
int largestRegion(int M[][COL], bool vis[][COL])
{
  int count = 0;
  int maxi = 0;
  for (int i = 0; i < ROW; i++)
  {
    for (int j = 0; j < COL; j++)
    {
      if (!vis[i][j])
      {
        dfs(i, j, M, vis, &count);
        maxi = max(maxi, count);
        count = 0;
      }
    }
  }
  return maxi;
}

int main()
{
  int M[][COL] = {{0, 0, 1, 1, 0},
                  {1, 0, 1, 1, 0},
                  {0, 1, 0, 0, 0},
                  {0, 0, 0, 0, 1}};

  bool vis[][COL] = {{0, 0, 0, 0, 0},
                     {0, 0, 0, 0, 0},
                     {0, 0, 0, 0, 0},
                     {0, 0, 0, 0, 0}};

  cout << largestRegion(M, vis);

  return 0;
}