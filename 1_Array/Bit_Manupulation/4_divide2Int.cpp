int divideTwoInteger(int dividend, int divisor)
{
  // Write your code here.
  int sign = ((dividend < 0) ^ (divisor < 0)) ? -1 : 1;

  dividend = abs(dividend);
  divisor = abs(divisor);

  int quotent = 0;
  while (dividend >= divisor)
  {
    dividend -= divisor;
    ++quotent;
  }

  return quotent * sign;
}
