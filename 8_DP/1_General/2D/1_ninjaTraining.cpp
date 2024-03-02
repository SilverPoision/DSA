// Memoization
int recure(int days, int last, vector<vector<int>> points, vector<vector<int>> dp)
{
  if (days == 0)
  {
    int maxi = 0;
    for (int task = 0; task < 3; task++)
    {
      if (task != last)
      {
        maxi = max(maxi, points[0][task]);
      }
    }
    return maxi;
  }

  if (dp[days][last] != -1)
  {
    return dp[days][last];
  }

  int maxi = 0;
  for (int task = 0; task < 3; task++)
  {
    if (task != last)
    {
      int point = points[days][task] + recure(days - 1, task, points, dp);
      maxi = max(maxi, point);
    }
  }
  return dp[days][last] = maxi;
}

int ninjaTraining(int n, vector<vector<int>> &points)
{
  vector<vector<int>> dp(n, vector<int>(4, -1));
  return recure(n - 1, -1, points, dp);
}

// Tabulation

int ninjaTraining(int n, vector<vector<int>> &points)
{
  vector<vector<int>> dp(n, vector<int>(4, 0));
  dp[0][0] = max(points[0][1], points[0][2]);
  dp[0][1] = max(points[0][0], points[0][2]);
  dp[0][2] = max(points[0][0], points[0][1]);
  dp[0][3] = max(max(points[0][2], points[0][1]), points[0][0]);

  for (int day = 1; day < n; day++)
  {
    for (int last = 0; last < 4; last++)
    {
      dp[day][last] = 0;
      for (int task = 0; task < 3; task++)
      {
        if (task != last)
        {
          int point = points[day][task] + dp[day - 1][task];
          dp[day][last] = max(dp[day][last], point);
        }
      }
    }
  }
  return dp[n - 1][3];
}

// S.O
int ninjaTraining(int n, vector<vector<int>> &points)
{
  vector<int> prev(4, 0);
  prev[0] = max(points[0][1], points[0][2]);
  prev[1] = max(points[0][0], points[0][2]);
  prev[2] = max(points[0][0], points[0][1]);
  prev[3] = max(max(points[0][2], points[0][1]), points[0][0]);

  for (int day = 1; day < n; day++)
  {
    vector<int> temp(4, 0);
    for (int last = 0; last < 4; last++)
    {
      temp[last] = 0;
      for (int task = 0; task < 3; task++)
      {
        if (task != last)
        {
          int point = points[day][task] + prev[task];
          temp[last] = max(temp[last], point);
        }
      }
    }
    prev = temp;
  }
  return prev[3];
}
