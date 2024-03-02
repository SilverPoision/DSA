class Solution
{
public:
  // https://leetcode.com/problems/minimize-the-maximum-of-two-arrays/
  // https://www.youtube.com/watch?v=B3ijZEEaJsE
  int gcd(int a, int b)
  {
    if (b == 0)
      return a;

    return gcd(b, a % b);
  }
  int minimizeSet(int divisor1, int divisor2, int uniqueCnt1, int uniqueCnt2)
  {
    long l = 1, r = (int)2e9;

    int x, y, z;
    long ans = r;
    long lcm = (((long)divisor1 * (long)divisor2) / gcd(divisor1, divisor2));

    while (l <= r)
    {
      long mid = (l + r) >> 1;
      x = (int)(mid - (mid / divisor1));
      y = (int)(mid - (mid / divisor2));
      z = (int)(mid - (mid / lcm));

      if (x < uniqueCnt1 || y < uniqueCnt2 || z < uniqueCnt1 + uniqueCnt2)
      {
        l = mid + 1;
      }
      else
      {
        ans = min((int)ans, (int)mid);
        r = mid - 1;
      }
    }
    return (int)ans;
  }
};