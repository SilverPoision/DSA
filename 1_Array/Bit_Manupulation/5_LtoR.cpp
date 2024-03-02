int findX(int x)
{
  if (x % 4 == 0)
    return x;
  if (x % 4 == 1)
    return 1;
  if (x % 4 == 2)
    return x + 1;

  return 0;
}

int findXOR(int L, int R)
{
  // Write your code here.
  return findX(L - 1) ^ findX(R);
}