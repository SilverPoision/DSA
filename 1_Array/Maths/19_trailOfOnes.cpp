class Solution
{
public:
  // https://www.geeksforgeeks.org/problems/trail-of-ones3242/1
  // https://www.youtube.com/watch?v=0Svz-yADx60
  int numberOfConsecutiveOnes(int n)
  {
    // code here
    int a = 0, b = 1;
    int mod = 1e9 + 7;

    if (n == 2)
      return 1;

    int ans = 1;

    for (int i = 3; i <= n; i++)
    {
      int c = (a + b) % mod;
      ans = ((ans * 2) % mod + c) % mod;
      a = b;
      b = c;
    }

    return ans;
  }
};