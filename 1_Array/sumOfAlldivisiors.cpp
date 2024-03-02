int sumOfAllDivisors(int n)
{
  if (n == 1)
    return 1;
  int sum = 0;
  for (int i = 1; i <= sqrt(n); i++)
  {
    if (n % i == 0)
    {
      sum += i;
      if (n / i != i)
        sum += n / i;
    }
  }

  return sum + sumOfAllDivisors(n - 1);
}