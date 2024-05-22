class Solution
{
public:
  // https://www.geeksforgeeks.org/problems/divisor-game-1664432414/1
  // https://www.youtube.com/watch?v=UQICoMbZH-M
  bool divisorGame(int n)
  {
    // code here
    if (n <= 1)
      return false;

    for (int i = 1; i < n; i++)
    {
      if (n % i == 0)
        return !divisorGame(n - i);
    }

    return false;
  }
}