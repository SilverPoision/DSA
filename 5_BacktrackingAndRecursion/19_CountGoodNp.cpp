class Solution
{
public:
  int mod = 1e9 + 7;
  long long pow(long long x, long long n)
  {
    if (n == 0)
      return 1;

    long long res = pow(x, n / 2);
    res *= res;

    if (n % 2)
      res *= x;
    res = res % mod;

    return res;
  }
  int countGoodNumbers(long long n)
  {
    long long odd = n / 2;
    long long even = (n / 2) + (n % 2);
    return (pow(5, even) * pow(4, odd)) % mod;
  }
};