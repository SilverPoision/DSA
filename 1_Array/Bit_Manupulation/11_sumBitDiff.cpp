class Solution
{
public:
  // https://www.geeksforgeeks.org/problems/sum-of-bit-differences2937/1
  // https://www.youtube.com/watch?v=cfizo_K7e0o
  long long sumBitDifferences(int arr[], int n)
  {
    // code here
    long long sum = 0;
    for (int i = 0; i < 32; i++)
    {
      long long cnt = 0;
      for (int j = 0; j < n; j++)
      {
        if (arr[j] & (1 << i))
        {
          cnt++;
        }
      }
      sum += (cnt * (n - cnt)) << 1;
    }

    return sum;
  }
};