class Solution
{
public:
  int findKthPositive(vector<int> &arr, int k)
  {
    int low = 0, high = arr.size() - 1;

    while (low <= high)
    {
      int mid = (low + high) / 2;

      int missingNo = arr[mid] - (mid + 1);

      if (missingNo < k)
        low = mid + 1;
      else
        high = mid - 1;
    }

    return low + k;
  }
};