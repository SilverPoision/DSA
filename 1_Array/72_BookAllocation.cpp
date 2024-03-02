class Solution
{
public:
  bool possibleAllocation(int A[], int N, int M, int mid)
  {
    int std = 0;
    int temp = 0;

    for (int i = 0; i < N; i++)
    {
      if ((temp + A[i]) > mid)
      {
        std++;
        temp = A[i];
        if (A[i] > mid)
          return false;
      }
      else
      {
        temp += A[i];
      }
    }

    return std < M;
  }

  // Function to find minimum number of pages.
  int findPages(int A[], int N, int M)
  {
    // code here
    if (M > N)
      return -1;

    int low = 1e9, high = 0;

    for (int i = 0; i < N; i++)
    {
      low = min(low, A[i]);
      high += A[i];
    }

    while (low <= high)
    {
      int mid = (low + high) / 2;

      if (possibleAllocation(A, N, M, mid))
      {
        high = mid - 1;
      }
      else
      {
        low = mid + 1;
      }
    }

    return low;
  }
};