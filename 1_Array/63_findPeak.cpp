class Solution
{
public:
  int findPeakElement(vector<int> &arr)
  {
    int n = arr.size();

    int low = 0, high = n - 1;

    while (low <= high)
    {
      int mid = (low + high) / 2;

      if (mid > 0 && arr[mid] < arr[mid - 1])
      {
        high = mid - 1;
      }
      else if (mid < n - 1 && arr[mid] < arr[mid + 1])
      {
        low = mid + 1;
      }
      else
      {
        return mid;
      }
    }

    return -1;
  }
};
