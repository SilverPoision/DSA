class Solution
{
public:
  // https://www.geeksforgeeks.org/problems/max-sum-in-the-configuration/1
  // https://www.youtube.com/watch?v=yroWfS5P2E4
  long long max_sum(int a[], int n)
  {
    // Your code here
    long long maxi = 0, sum = 0, sz = 0;

    for (int i = 0; i < n; i++)
    {
      sum += (long long)a[i];
      sz += i * (long long)a[i];
    }

    maxi = sz;

    for (int i = 0; i < n; i++)
    {
      sz += sum - ((long long)n * (long long)a[n - 1 - i]);
      maxi = max(maxi, sz);
    }

    return maxi;
  }
};