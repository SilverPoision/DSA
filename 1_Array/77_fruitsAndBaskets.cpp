int findMaxFruits(vector<int> &arr, int n)
{
  // Write your code here.
  map<int, int> hash;

  int i = 0, j = 0;
  int maxi = 0;

  while (i < n && j < n)
  {
    if (hash.size() < 2 || hash.find(arr[j]) != hash.end())
    {
      hash[arr[j]]++;
      maxi = max(maxi, j - i + 1);
      j++;
    }
    else
    {
      while (hash.size() >= 2)
      {
        hash[arr[i]]--;
        if (hash[arr[i]] == 0)
          hash.erase(arr[i]);
        i++;
      }
    }
  }

  return maxi;
}