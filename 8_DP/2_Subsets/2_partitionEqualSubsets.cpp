bool func(int k, vector<int> &arr)
{
  vector<bool> prev(k + 1, false), curr(k + 1, false);
  prev[0] = curr[0] == true;
  if (arr[0] <= k)
    prev[arr[0]] = true;

  for (int ind = 1; ind < arr.size(); ind++)
  {
    for (int tar = 1; tar <= k; tar++)
    {
      bool notTake = prev[tar];
      bool take = false;
      if (tar >= arr[ind])
        take = prev[tar - arr[ind]];
      curr[tar] = notTake || take;
    }
    prev = curr;
  }
  return prev[k];
}

bool canPartition(vector<int> &arr, int n)
{
  int totSum = 0;
  for (auto it : arr)
  {
    totSum += it;
  }

  if (totSum % 2)
    return false;
  return func(totSum / 2, arr);
}
