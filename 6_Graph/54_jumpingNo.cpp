#include <bits/stdc++.h>

void bfs(int i, int n, vector<int> &ans)
{
  queue<int> q;
  q.push(i);

  while (!q.empty())
  {
    int num = q.front();
    q.pop();
    if (num <= n)
    {
      ans.push_back(num);
      int lastDigit = num % 10;

      if (lastDigit == 0)
      {
        q.push((num * 10 + lastDigit + 1));
      }
      else if (lastDigit == 9)
      {
        q.push((num * 10 + lastDigit - 1));
      }
      else
      {
        q.push((num * 10 + lastDigit - 1));
        q.push((num * 10 + lastDigit + 1));
      }
    }
  }
}

vector<int> findJumpingNumbers(int n)
{
  vector<int> ans;
  ans.push_back(0);

  for (int i = 1; i <= 9 && i <= n; i++)
  {
    bfs(i, n, ans);
  }
  sort(ans.begin(), ans.end());
  return ans;
}