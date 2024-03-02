#include <bits/stdc++.h>
using namespace std;

int fibb(int n, vector<int> &dp)
{
  if (n <= 1)
  {
    return n;
  }

  if (dp[n] != -1)
  {
    return dp[n];
  }

  dp[n] = fibb(n - 1, dp) + fibb(n - 2, dp);
  return dp[n];
}

int main()
{
  int n;
  cin >> n;

  vector<int> dp(n * n, -1);

  cout << fibb(n, dp) << endl;
  return 0;
}

/*
Tabulation
#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n;
  cin >> n;

  vector<int> dp(n * n, -1);
  dp[0] = 0;
  dp[1] = 1

  for(int i = 2; i <=n; i++) {
    dp[i] = dp[i-1] + dp[i-2];
  }

  return dp[n];

  cout << fibb(n, dp) << endl;
  return 0;
}
*/

/*
Space Optimization
int fibonacciNumber(int n){
   int a = 0, b = 1, c,i;
    int mod = (int)1e9 + 7;

  if ( n== 0) {
      return a;
  }

  for(i = 2; i <= n; i++) {
     c = (a+b) % mod;
     a = b;
     b = c;
  }
  return b;
}
*/