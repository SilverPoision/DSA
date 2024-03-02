bool fun(int index, vector<int> num, int sum, int k)
{
  if (sum == k && index >= num.size())
  {
    return true;
  }
  if (index >= num.size())
  {
    return false;
  }

  bool n = fun(index + 1, num, sum, k);
  bool m = fun(index + 1, num, sum + num[index], k);
  return n || m;
}

bool subsetSumToK(int n, int k, vector<int> &arr)
{
  return fun(0, arr, 0, k);
}