int calcGCD(int n, int m)
{
  // Write your code here.
  // eculidean algo
  while (n > 0 && m > 0)
  {
    if (n > m)
      n = n % m;
    else
      m = m % n;
  }

  if (n == 0)
    return m;
  else
    return n;
}

// https://www.youtube.com/watch?v=b1ZV2VzNqAo

int gcd(int a, int b)
{
  if (b == 0)
    return a;

  return gcd(b, a % b);
}

int lcm(int a, int b)
{
  return (a * b) / gcd(a, b);
}