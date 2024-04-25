// C++ program for Knight Tour problem
#include <bits/stdc++.h>
using namespace std;

#define N 8
int xMove[8] = {2, 1, -1, -2, -2, -1, 1, 2};
int yMove[8] = {1, 2, 2, 1, -1, -2, -2, -1};

/* A utility function to check if i,j are
valid indexes for N*N chessboard */

/* A utility function to print
solution matrix sol[N][N] */
void printSolution(int sol[N][N])
{
  for (int x = 0; x < N; x++)
  {
    for (int y = 0; y < N; y++)
      cout << " " << setw(2) << sol[x][y] << " ";
    cout << endl;
  }
}

bool isSafe(int x, int y, int sol[N][N])
{
  return (x >= 0 && x < N && y >= 0 && y < N && sol[x][y] == -1);
}

int solveKTUtil(int r, int c, int move, int sol[N][N])
{
  if (move == (N * N))
  {
    return 1;
  }

  for (int k = 0; k < 8; k++)
  {
    int nextR = r + xMove[k];
    int nextC = c + yMove[k];

    if (isSafe(nextR, nextC, sol))
    {
      sol[nextR][nextC] = move;
      if (solveKTUtil(nextR, nextC, move + 1, sol) == 1)
      {
        return 1;
      }
      else
      {
        sol[nextR][nextC] = -1;
      }
    }
  }
  return 0;
}

/* This function solves the Knight Tour problem using
Backtracking. This function mainly uses solveKTUtil()
to solve the problem. It returns false if no complete
tour is possible, otherwise return true and prints the
tour.
Please note that there may be more than one solutions,
this function prints one of the feasible solutions. */
int solveKT()
{
  int sol[N][N];

  /* Initialization of solution matrix */
  for (int x = 0; x < N; x++)
  {
    for (int y = 0; y < N; y++)
    {
      sol[x][y] = -1;
    }
  }

  /* Start from 0,0 and explore all tours using
  solveKTUtil() */
  sol[0][0] = 0;
  if (solveKTUtil(0, 0, 1, sol) == 0)
  {
    cout << "Solution does not exist" << endl;
    printSolution(sol);

    return 0;
  }
  else
    printSolution(sol);

  return 1;
}

// Driver Code
int main()
{
  // Function Call
  solveKT();
  return 0;
}

// This code is contributed by ShubhamCoder
