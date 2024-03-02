class Solution
{
public:
  long long countKdivPairs(int A[], int n, int k)
  {
    // code here
    map<int, int> m;
    long ans = 0;

    for (int i = 0; i < n; i++)
    {
      int rem = A[i] % k;

      if (rem != 0)
      {
        ans += m[k - rem];
      }
      else
      {
        ans += m[0];
      }

      m[rem]++;
    }

    return ans;
  }
};