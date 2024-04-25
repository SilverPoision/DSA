int uniqueBinaryTree(int a, int b)
{
  // Write your code here.
  if ((a == 2 || b == 2) && a != b)
    return 1;
  return 0;
}