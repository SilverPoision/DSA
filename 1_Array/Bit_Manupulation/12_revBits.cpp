class Solution
{
public:
  long long reversedBits(long long x)
  {
    // code here
    long long res = 0;
    for (int i = 0; i < 32; i++)
    {
      res = res << 1;
      if (x & 1)
      {
        res |= 1;
      }
      x = x >> 1;
      // res = res<<1;
    }

    return res;
  }
};