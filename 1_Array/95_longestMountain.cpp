class Solution
{
public:
  int longestMountain(vector<int> &arr)
  {
    // longest inc prefix and longest decresing suffix
    int n = arr.size();
    vector<int> suffix(n, 1), prefix(n, 1);

    for (int i = 1; i < n; i++)
    {
      if (arr[i] > arr[i - 1])
        prefix[i] = prefix[i - 1] + 1;
    }
    for (int i = n - 2; i >= 0; i--)
    {
      if (arr[i] > arr[i + 1])
        suffix[i] = suffix[i + 1] + 1;
    }

    int maxi = 0;
    for (int i = 0; i < n; i++)
    {
      if (suffix[i] == 1 || prefix[i] == 1)
        continue;
      maxi = max(maxi, suffix[i] + prefix[i] - 1);
    }

    return maxi > 1 ? maxi : 0;
  }
};