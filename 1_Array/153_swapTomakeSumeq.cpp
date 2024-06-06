class Solution
{
public:
  // https://www.geeksforgeeks.org/problems/swapping-pairs-make-sum-equal4142/1
  int findSwapValues(int a[], int n, int b[], int m)
  {
    // Your code goes here
    unordered_map<int, int> hash;
    int suma = 0;
    int sumb = 0;

    for (int i = 0; i < m; i++)
    {
      hash[b[i]]++;
      sumb += b[i];
    }

    for (int i = 0; i < n; i++)
      suma += a[i];

    if ((suma + sumb) % 2)
      return -1;

    int temp = (suma + sumb) / 2;

    for (int i = 0; i < n; i++)
    {
      int req = temp - (suma - a[i]);

      if (hash.find(req) != hash.end())
        return 1;
    }

    return -1;
  }
};