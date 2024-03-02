vector<int> MinimumCoins(int n)
{
  // Write your code here
  vector<int> denominations = {1, 2, 5, 10, 20, 50, 100, 500, 1000};
  vector<int> ans;

  for (int i = denominations.size() - 1; i >= 0; i--)
  {
    if (denominations[i] > n)
      continue;

    if (n % denominations[i] == 0)
    {
      for (int k = 0; k < (n / denominations[i]); k++)
      {
        ans.push_back(denominations[i]);
      }
      return ans;
    }
    else
    {
      while (n >= denominations[i])
      {
        ans.push_back(denominations[i]);
        n -= denominations[i];
      }
    }
  }

  return ans;
}