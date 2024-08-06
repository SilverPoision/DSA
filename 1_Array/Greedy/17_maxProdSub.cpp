class Solution
{
public:
  // https://www.geeksforgeeks.org/problems/maximum-product-subset-of-an-array/1
  long long int findMaxProduct(vector<int> &arr)
  {
    // Write your code here
    int n = arr.size();
    if (n == 1)
      return arr[0];

    int mod = 1e9 + 7;

    long long int prod = 1;
    int mini = -1e9;
    int c = 0;
    int neg = 0;
    for (auto it : arr)
    {
      if (it == 0)
      {
        c++;
        continue;
      }

      prod = (it * prod) % mod;
      if (it < 0)
      {
        mini = max(mini, it);
        neg++;
      }
    }

    if (c == n)
      return 0;
    if (neg == 1 && c + neg == n)
      return 0;

    if (neg % 2 == 0)
      return prod;
    return prod / mini;
  }
};