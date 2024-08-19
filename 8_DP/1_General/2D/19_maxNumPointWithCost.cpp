class Solution
{
public:
  // https://leetcode.com/problems/maximum-number-of-points-with-cost/?envType=daily-question&envId=2024-08-17
  long long maxPoints(vector<vector<int>> &p)
  {
    int n = p.size();
    int m = p[0].size();
    vector<long long> row(m, 0);

    for (int i = 0; i < m; i++)
    {
      row[i] = p[0][i];
    }

    for (int r = 1; r < n; r++)
    {
      vector<long long> left(m, 0), right(m, 0), next_row(m, 0);

      left[0] = row[0];
      for (int i = 1; i < m; i++)
      {
        left[i] = max(left[i - 1] - 1, row[i]);
      }

      right[m - 1] = row[m - 1];
      for (int i = m - 2; i >= 0; i--)
      {
        right[i] = max(right[i + 1] - 1, row[i]);
      }

      for (int i = 0; i < m; i++)
      {
        next_row[i] = max(left[i], right[i]) + p[r][i];
      }
      row = next_row;
    }

    return *max_element(row.begin(), row.end());
  }
};

class Solution
{
public:
  vector<vector<int>> dp;
  long long solve(int i, int j, vector<vector<int>> &p)
  {
    if (i == p.size())
    {
      return 0;
    }

    if (dp[i][j] != -1)
      return dp[i][j];

    long long maxi = 0;
    for (int k = 0; k < p[0].size(); k++)
    {
      int minus = 0;
      if (i != 0)
        minus = abs(j - k);
      maxi = max(maxi, p[i][k] - minus + solve(i + 1, k, p));
    }

    return dp[i][j] = maxi;
  }
  long long maxPoints(vector<vector<int>> &p)
  {
    dp = vector<vector<int>>(p.size(), vector<int>(p[0].size(), -1));
    return solve(0, 0, p);
  }
};