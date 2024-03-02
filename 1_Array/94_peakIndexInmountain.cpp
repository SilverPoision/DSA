class Solution
{
  // Another questions can be no of mountains in an array and
  // that can be found by fidning the suffix and prefix of the array just like kumar k
public:
  int peakIndexInMountainArray(vector<int> &arr)
  {
    int n = arr.size();
    int low = 0, high = n - 1;

    while (low <= high)
    {
      int mid = (high + low) / 2;

      if (high - low + 1 == 2)
      {
        if (arr[high] > arr[low])
          return high;
        else
          return low;
      }

      if (mid > 0 && mid < n - 1 && arr[mid] > arr[mid - 1] && arr[mid] > arr[mid + 1])
      {
        return mid;
      }
      if (mid > 0 && mid < n - 1 && arr[mid] > arr[mid - 1] && arr[mid] < arr[mid + 1])
      {
        low = mid + 1;
      }
      else
      {
        high = mid - 1;
      }
    }

    return low;
  }
};

// More optimal
class Solution
{
public:
  int peakIndexInMountainArray(vector<int> &arr)
  {
    int l = 0;
    int r = arr.size() - 1;

    while (l < r) // can be !=
    {
      int m = l + (r - l) / 2;
      // if conditions is not defined to exit the loop then we dont need to
      // move right pointer by m-1 just do m and they will converge to one index and the loop will end
      if (arr[m] > arr[m + 1])
      {
        r = m; // because if m become last index then it will throw error
      }
      else
      {
        l = m + 1;
      }
    }
    return l;
  }
};