class Solution
{
public:
  int fun(int e, int f, vector<vector<int>> &dp)
  {
    if (f == 0 || f == 1)
      return f;
    if (e == 1)
      return f;

    if (dp[e][f] != -1)
      return dp[e][f];

    int mini = INT_MAX;
    for (int i = 1; i <= f; i++)
    {
      int temp = 1 + max(fun(e - 1, i - 1, dp), fun(e, f - i, dp)); // because of the nature of the loop we have to take it this way see aditya verma vid 21:00
      mini = min(temp, mini);
    }

    return dp[e][f] = mini;
  }

  int superEggDrop(int k, int n)
  {
    vector<vector<int>> dp(k + 1, vector<int>(n + 1, -1));
    return fun(k, n, dp);
  }
};

// Tab
class Solution
{
public:
  int superEggDrop(int n, int k)
  {
    int eggFloor[n + 1][k + 1];
    int res;
    int i, j, x;

    // We need one trial for one floor and 0
    // trials for 0 floors
    for (i = 1; i <= n; i++)
    {
      eggFloor[i][1] = 1;
      eggFloor[i][0] = 0;
    }

    // We always need j trials for one egg
    // and j floors.
    for (j = 1; j <= k; j++)
      eggFloor[1][j] = j;

    // Fill rest of the entries in table using
    // optimal substructure property
    for (i = 2; i <= n; i++)
    {
      for (j = 2; j <= k; j++)
      {
        eggFloor[i][j] = INT_MAX;
        for (x = 1; x <= j; x++)
        {
          res = 1 + max(
                        eggFloor[i - 1][x - 1],
                        eggFloor[i][j - x]);
          if (res < eggFloor[i][j])
            eggFloor[i][j] = res;
        }
      }
    }

    // eggFloor[n][k] holds the result
    return eggFloor[n][k];
  }
};