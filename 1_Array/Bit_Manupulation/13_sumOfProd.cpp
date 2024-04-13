class Solution
{
public:
  // https://www.geeksforgeeks.org/problems/sum-of-products5049/1
  // https://www.youtube.com/watch?v=1qqeHFoQCYs
  long long pairAndSum(int n, long long arr[])
  {
    // code here
    long long sum = 0;

    for (int i = 0; i < 32; i++)
    {
      long long bits = 0;
      for (int k = 0; k < n; k++)
      {
        if (arr[k] & (1 << i))
        {
          bits++;
        }
      }
      sum += (1 << i) * ((bits * (bits - 1)) / 2);
    }

    return sum;
  }
};