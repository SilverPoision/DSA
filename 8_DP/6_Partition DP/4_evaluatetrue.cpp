#include <bits/stdc++.h>
#define ll long long
#define mod 1000000007

ll f(ll i, ll j, bool isTrue, string &exp, vector<vector<vector<ll>>> &dp)
{
  if (i > j)
    return 0;
  if (i == j)
  {
    if (isTrue)
    {
      return exp[i] == 'T';
    }
    else
    {
      return exp[i] == 'F';
    }
  }

  if (dp[i][j][isTrue] != -1)
  {
    return dp[i][j][isTrue];
  }

  ll ways = 0;

  for (ll ind = i + 1; ind <= j - 1; ind += 2)
  {
    ll rT = f(i, ind - 1, 1, exp, dp);
    ll rF = f(i, ind - 1, 0, exp, dp);
    ll lT = f(ind + 1, j, 1, exp, dp);
    ll lF = f(ind + 1, j, 0, exp, dp);

    if (exp[ind] == '&')
    {
      if (isTrue)
      {
        ways += (rT * lT) % mod;
      }
      else
      {
        ways += (rT * lF) % mod + (rF * lT) % mod + (rF * lF) % mod;
      }
    }
    else if (exp[ind] == '|')
    {
      if (isTrue)
      {
        ways += (rT * lT) % mod + (rT * lF) % mod + (rF * lT) % mod;
      }
      else
      {
        ways += (rF * lF) % mod;
      }
    }
    else if (exp[ind] == '^')
    {
      if (isTrue)
      {
        ways += (rT * lF) % mod + (rF * lT) % mod;
      }
      else
      {
        ways += (rF * lF) % mod + (rT * lT) % mod;
      }
    }
  }
  return dp[i][j][isTrue] = ways % mod;
}

int evaluateExp(string &exp)
{
  int n = exp.size();
  vector<vector<vector<ll>>> dp(n, vector<vector<ll>>(n, vector<ll>(2, -1)));
  return f(0, n - 1, 1, exp, dp);
}

// Tab My
#include <bits/stdc++.h>
#define ll long long int
#define mod 1000000007

int evaluateExp(string &exp)
{
  int n = exp.size();
  vector<vector<vector<ll>>> dp(n, vector<vector<ll>>(n, vector<ll>(2, 0)));
  for (int i = 0; i <= n; i++)
  {
    dp[i][i][1] = exp[i] == 'T';
    dp[i][i][0] = exp[i] == 'F';
  }

  for (ll i = n - 1; i >= 0; i--)
  {
    for (ll j = i + 1; j < n; j++)
    {
      for (ll isTrue = 0; isTrue < 2; isTrue++)
      {
        ll ways = 0;
        for (ll ind = i + 1; ind <= j - 1; ind += 2)
        {
          ll rT = dp[i][ind - 1][1];
          ll rF = dp[i][ind - 1][0];
          ll lT = dp[ind + 1][j][1];
          ll lF = dp[ind + 1][j][0];

          if (exp[ind] == '&')
          {
            if (isTrue)
            {
              ways += (rT * lT) % mod;
            }
            else
            {
              ways += (rT * lF) % mod + (rF * lT) % mod + (rF * lF) % mod;
            }
          }
          else if (exp[ind] == '|')
          {
            if (isTrue)
            {
              ways += (rT * lT) % mod + (rT * lF) % mod + (rF * lT) % mod;
            }
            else
            {
              ways += (rF * lF) % mod;
            }
          }
          else if (exp[ind] == '^')
          {
            if (isTrue)
            {
              ways += (rT * lF) % mod + (rF * lT) % mod;
            }
            else
            {
              ways += (rF * lF) % mod + (rT * lT) % mod;
            }
          }
        }
        dp[i][j][isTrue] = ways % mod;
      }
    }
  }
  return dp[0][n - 1][1];
}

// Tab
#define ll long long int
ll mod = 1000000007;
int evaluateExp(string &exp)
{
  int n = exp.length();
  vector<vector<vector<int>>> dp(n, vector<vector<int>>(n, vector<int>(2, 0)));
  for (int i = n - 1; i >= 0; i--)
  {
    for (int j = i; j < n; j++)
    {
      if (i == j)
      {
        dp[i][j][0] = (exp[i] == 'F');
        dp[i][j][1] = (exp[i] == 'T');
      }
      else
      {
        ll ways = 0;
        for (ll ind = i + 1; ind <= j - 1; ind += 2)
        {
          ll lt = dp[i][ind - 1][1] % mod;
          ll rt = dp[ind + 1][j][1] % mod;
          ll lf = dp[i][ind - 1][0] % mod;
          ll rf = dp[ind + 1][j][0] % mod;
          if (exp[ind] == '&')
          {
            dp[i][j][0] = (dp[i][j][0] + (lt * rf + lf * rt + lf * rf)) % mod;
            dp[i][j][1] = (dp[i][j][1] + (lt * rt)) % mod;
          }
          else if (exp[ind] == '|')
          {
            dp[i][j][0] = (dp[i][j][0] + (lf * rf)) % mod;
            dp[i][j][1] = (dp[i][j][1] + (lt * rf + lf * rt + lt * rt)) % mod;
          }
          else
          {
            dp[i][j][0] = (dp[i][j][0] + (lt * rt + lf * rf)) % mod;
            dp[i][j][1] = (dp[i][j][1] + (lt * rf + lf * rt)) % mod;
          }
        }
      }
    }
  }
  return dp[0][n - 1][1];
}