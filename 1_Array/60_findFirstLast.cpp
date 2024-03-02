class Solution
{
public:
  vector<int> searchRange(vector<int> &arr, int target)
  {
    int n = arr.size();
    int lower = n, upper = n;
    int low = 0, high = n - 1;

    while (low <= high)
    {
      int mid = (low + high) / 2;

      if (arr[mid] >= target)
      {
        lower = mid;
        high = mid - 1;
      }
      else
      {
        low = mid + 1;
      }
    }

    low = 0, high = n - 1;

    while (low <= high)
    {
      int mid = (low + high) / 2;

      if (arr[mid] > target)
      {
        upper = mid;
        high = mid - 1;
      }
      else
      {
        low = mid + 1;
      }
    }

    if (lower == n || arr[lower] != target)
      return {-1, -1};

    return {lower, upper - 1};
  }
};