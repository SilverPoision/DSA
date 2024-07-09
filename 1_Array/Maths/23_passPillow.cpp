class Solution
{
public:
  // https://leetcode.com/problems/pass-the-pillow/?envType=daily-question&envId=2024-07-06
  int passThePillow(int n, int time)
  {
    if (time < n)
      return time + 1;
    int k = time / (n - 1);
    int rem = time % (n - 1);

    if (k & 1)
    {
      return n - (rem);
    }
    return rem + 1;
  }
};