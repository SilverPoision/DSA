class Solution
{
public:
  int f(int i, int j, vector<int> &arr, map<pair<int, int>, int> &hash, vector<vector<int>> &dp)
  {
    if (i == j)
      return 0;

    if (dp[i][j] != -1)
      return dp[i][j];

    int ans = 1e9;
    for (int k = i; k < j; k++)
    {
      ans = min(ans, (hash[{i, k}] * hash[{i + 1, j}] + f(i, k, arr, hash, dp) + f(k + 1, j, arr, hash, dp)));
    }

    return dp[i][j] = ans;
  }
  int mctFromLeafValues(vector<int> &arr)
  {
    int n = arr.size();
    map<pair<int, int>, int> hash;
    vector<vector<int>> dp(n, vector<int>(n, -1));

    for (int i = 0; i < n; i++)
    {
      hash[{i, i}] = arr[i];
      for (int j = i + 1; j < n; j++)
      {
        hash[{i, j}] = max(arr[j], hash[{i, j - 1}]);
      }
    }
    return f(0, n - 1, arr, hash, dp);
  }
};

class Solution
{
public:
  int mctFromLeafValues(vector<int> &arr)
  {
    int n = arr.size();
    map<pair<int, int>, int> hash;
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

    for (int i = 0; i < n; i++)
    {
      hash[{i, i}] = arr[i];
      for (int j = i + 1; j < n; j++)
      {
        hash[{i, j}] = max(arr[j], hash[{i, j - 1}]);
      }
    }

    for (int i = n - 1; i >= 0; i--)
    {
      for (int j = 0; j < n; j++)
      {
        if (i >= j)
          continue;
        int ans = 1e9;
        for (int k = i; k < j; k++)
        {
          ans = min(ans, (hash[{i, k}] * hash[{i + 1, j}] + dp[i][k] + dp[k + 1][j]));
        }

        dp[i][j] = ans;
      }
    }

    return dp[0][n - 1];
  }
};