class Solution
{
public:
  // https://leetcode.com/problems/find-the-child-who-has-the-ball-after-k-seconds/
  int numberOfChild(int n, int k)
  {
    int round = (n * 2) - 2;
    k = k % round;
    bool flag = true;
    int i = 0;

    while (k--)
    {
      if (flag)
      {
        i++;
        if (i == n - 1)
          flag = false;
      }
      else
      {
        i--;
        if (i == 0)
          flag = true;
      }
      // k--;
    }

    return i;
  }
};

// optimal
class Solution
{
public:
  int numberOfChild(int n, int k)
  {
    n--;
    int numOf = k / n;
    int rem = k % n;

    if (numOf % 2 == 0)
    {
      return rem;
    }
    return n - rem;
  }
};