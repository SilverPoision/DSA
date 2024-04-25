class Solution
{
public:
  // https://www.geeksforgeeks.org/problems/maximum-sum-problem2211/1
  int solve(int n)
  {
    if (n <= 0)
      return 0;
    int o = n / 2;
    int t = n / 3;
    int th = n / 4;

    o = max(o, solve(o));
    t = max(t, solve(t));
    th = max(th, solve(th));

    return max(n, o + t + th);
  }
  int maxSum(int n)
  {
    // code here.
    return solve(n);
  }
};