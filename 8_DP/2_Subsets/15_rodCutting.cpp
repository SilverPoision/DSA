int func(int ind, vector<int> &price, int w, vector<vector<int>> &dp)
{
  if (ind == 0)
  {
    return w * price[ind];
  }

  if (dp[ind][w] != -1)
  {
    return dp[ind][w];
  }

  int notTake = func(ind - 1, price, w, dp);
  int take = 0;
  if (w >= ind + 1)
    take = price[ind] + func(ind, price, w - (ind + 1), dp);

  return dp[ind][w] = max(take, notTake);
}

int cutRod(vector<int> &price, int n)
{
  vector<vector<int>> dp(n, vector<int>(n + 1, -1));
  return func(n - 1, price, n, dp);
}

// Tab
int cutRod(vector<int> &price, int n)
{
  vector<vector<int>> dp(n, vector<int>(n + 1, 0));

  for (int i = 0; i <= n; i++)
  {
    dp[0][i] = i * price[0];
  }

  for (int ind = 1; ind < n; ind++)
  {
    for (int w = 0; w <= n; w++)
    {
      int notTake = dp[ind - 1][w];
      int take = 0;
      if (w >= ind + 1)
        take = price[ind] + dp[ind][w - (ind + 1)];
      dp[ind][w] = max(take, notTake);
    }
  }

  return dp[n - 1][n];
}

// S.O
int cutRod(vector<int> &price, int n)
{
  vector<int> prev(n + 1, 0), curr(n + 1, 0);

  for (int i = 0; i <= n; i++)
  {
    prev[i] = i * price[0];
  }

  for (int ind = 1; ind < n; ind++)
  {
    for (int w = 0; w <= n; w++)
    {
      int notTake = prev[w];
      int take = 0;
      if (w >= ind + 1)
        take = price[ind] + curr[w - (ind + 1)];
      curr[w] = max(take, notTake);
    }
    prev = curr;
  }

  return prev[n];
}

// Ultra s.o
int cutRod(vector<int> &price, int n)
{
  vector<int> prev(n + 1, 0);

  for (int i = 0; i <= n; i++)
  {
    prev[i] = i * price[0];
  }

  for (int ind = 1; ind < n; ind++)
  {
    for (int w = 0; w <= n; w++)
    {
      int notTake = prev[w];
      int take = 0;
      if (w >= ind + 1)
        take = price[ind] + prev[w - (ind + 1)];
      prev[w] = max(take, notTake);
    }
  }

  return prev[n];
}
