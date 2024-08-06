class Solution
{
public:
  // https://leetcode.com/problems/count-number-of-teams/description/?envType=daily-question&envId=2024-07-29
  // try with fenwik tree
  int numTeams(vector<int> &r)
  {
    int n = r.size();

    vector<int> pre(n), suf(n);
    for (int i = 0; i < n; i++)
    {
      for (int j = i + 1; j < n; j++)
      {
        if (r[j] > r[i])
          pre[i]++;
        if (r[j] < r[i])
          suf[i]++;
      }
    }

    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
      for (int j = i + 1; j < n; j++)
      {
        if (r[i] < r[j])
          cnt += pre[j];
        else if (r[i] > r[j])
          cnt += suf[j];
      }
    }

    return cnt;
  }
};

class Solution
{
public:
  int numTeams(vector<int> &rating)
  {
    int n = rating.size();

    int teams = 0;

    for (int j = 1; j < n - 1; j++)
    {

      int countSmallerLeft = 0;
      int countLargerLeft = 0;
      int countSmallerRight = 0;
      int countLargerRight = 0;

      for (int i = 0; i < j; i++)
      {
        if (rating[i] < rating[j])
        {
          countSmallerLeft++;
        }
        else if (rating[i] > rating[j])
        {
          countLargerLeft++;
        }
      }

      for (int k = j + 1; k < n; k++)
      {
        if (rating[j] < rating[k])
        {
          countLargerRight++;
        }
        else if (rating[j] > rating[k])
        {
          countSmallerRight++;
        }
      }

      teams += (countLargerLeft * countSmallerRight) + (countSmallerLeft * countLargerRight);
    }

    return teams;
  }
};

class Solution
{
public:
  vector<vector<vector<int>>> dp;
  int solve(int i, vector<int> &r, int k, bool inc, int prev)
  {
    if (k == 3)
      return 1;
    if (i == r.size())
      return 0;

    if (dp[k][prev + 1][i] != -1)
      return dp[k][prev + 1][i];

    long long ans = 0;
    if (inc)
    {
      if (prev == -1 || r[prev] < r[i])
      {
        ans = ans + solve(i + 1, r, k + 1, inc, i);
      }
    }
    else
    {
      if (prev == -1 || r[prev] > r[i])
      {
        ans = ans + solve(i + 1, r, k + 1, inc, i);
      }
    }

    return dp[k][prev + 1][i] = ans + solve(i + 1, r, k, inc, prev);
  }
  int numTeams(vector<int> &r)
  {
    dp = vector<vector<vector<int>>>(4, vector<vector<int>>(r.size() + 1, vector<int>(r.size(), -1)));
    long long ans = solve(0, r, 0, true, -1);
    dp = vector<vector<vector<int>>>(4, vector<vector<int>>(r.size() + 1, vector<int>(r.size(), -1)));
    ans += solve(0, r, 0, false, -1);

    return ans;
  }
};