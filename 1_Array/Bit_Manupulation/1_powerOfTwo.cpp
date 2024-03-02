bool isPowerOfTwo(int n)
{
  // Write your code here.
  return ((n & (n - 1)) == 0);
}