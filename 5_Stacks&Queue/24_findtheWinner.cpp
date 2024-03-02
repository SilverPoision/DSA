class Solution
{
public:
  // https://leetcode.com/problems/find-the-winner-of-the-circular-game/
  int solve(int n, int k)
  {
    if (n == 1)
    {
      return 0;
    }

    return (solve(n - 1, k) + k) % n;
  }
  int findTheWinner(int n, int k)
  {
    return solve(n, k) + 1;
  }
};

class Solution
{
public:
  int findTheWinner(int n, int k)
  {
    queue<int> q;
    for (int i = 1; i <= n; i++)
    {
      q.push(i);
    }
    while (q.size() != 1)
    {
      int x = k;
      while (x > 1)
      {
        int r = q.front();
        q.pop();
        q.push(r);
        x--;
      }
      q.pop();
    }
    return q.front();
  }
};

class Solution
{
public:
  int findTheWinner(int n, int k)
  {
    queue<int> currQ;
    queue<int> tempQ;

    for (int i = 1; i <= n; i++)
    {
      currQ.push(i);
    }

    while (currQ.size() > 1)
    {
      int times = k % currQ.size();
      if (times == 0)
      {
        times = currQ.size();
      }
      queue<int> t;

      while (times > 0)
      {
        times--;
        if (times != 0)
        {
          t.push(currQ.front());
        }
        currQ.pop();
      }

      while (!currQ.empty())
      {
        tempQ.push(currQ.front());
        currQ.pop();
      }
      while (!t.empty())
      {
        tempQ.push(t.front());
        t.pop();
      }

      swap(currQ, tempQ);
    }

    return currQ.front();
  }
};