int n = arr.size();

int up = 1, down = 1;
for (int i = 1; i < n; i++)
{
  if (arr[i] > arr[i - 1])
  {
    up = down + 1;
  }
  else if (arr[i] < arr[i - 1])
  {
    down = up + 1;
  }
}

return max(up, down);

class Solution
{
public:
  vector<vector<vector<int>>> dp;
  int solve(int i, vector<int> &arr, int prev, bool h)
  {
    if (i == arr.size())
      return 0;

    if (dp[i][prev + 1][h] != -1)
      return dp[i][prev + 1][h];

    int ans = 0;

    if (prev == -1 || (h && arr[i] > arr[prev]) || (!h && arr[i] < arr[prev]))
    {
      ans = max(ans, 1 + solve(i + 1, arr, i, !h));
      if (prev == -1)
        ans = max(ans, 1 + solve(i + 1, arr, i, h));
    }
    ans = max(ans, solve(i + 1, arr, prev, h));

    return dp[i][prev + 1][h] = ans;
  }
  int alternatingMaxLength(vector<int> &arr)
  {
    // Code here
    dp = vector<vector<vector<int>>>(arr.size(), vector<vector<int>>(arr.size() + 1, vector<int>(2, -1)));
    return solve(0, arr, -1, false);
  }
};