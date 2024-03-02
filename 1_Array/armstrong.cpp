bool checkArmstrong(int n)
{ // Write your code here
  int total = n;
  int remainder;
  int sum = 0;

  int digits = 0;
  while (n)
  {
    n /= 10;
    digits++;
  }

  n = total;

  while (n > 0)
  {
    remainder = n % 10;
    sum = sum + pow(remainder, digits);
    n /= 10;
  }
  if (sum == total)
    return true;
  else
    return false;
}
