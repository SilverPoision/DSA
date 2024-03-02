class Solution
{
public:
  int candy(vector<int> &arr)
  {
    int n = arr.size();
    vector<int> candies(n, 1);

    for (int i = 1; i < n; i++)
    {
      if (arr[i] > arr[i - 1])
      {
        candies[i] = candies[i - 1] + 1;
      }
    }
    for (int i = n - 2; i >= 0; i--)
    {
      if (arr[i] > arr[i + 1])
      {
        candies[i] = max(candies[i], candies[i + 1] + 1);
      }
    }

    int candy = 0;
    for (int i = 0; i < n; i++)
    {
      candy += candies[i];
    }

    return candy;
  }
};