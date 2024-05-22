class Solution
{
public:
  // https://www.geeksforgeeks.org/problems/find-the-highest-number2259/1
  int findPeakElement(vector<int> &a)
  {
    // Code here.
    int n = a.size();
    int l = 1, r = n - 2;

    if (a[n - 1] > a[n - 2])
      return a[n - 1];

    while (l <= r)
    {
      int mid = l + (r - l) / 2;

      if (a[mid] > a[mid - 1] && a[mid] > a[mid + 1])
      {
        return a[mid];
      }
      else if (a[mid] > a[mid - 1])
      {
        l = mid + 1;
      }
      else
      {
        r = mid - 1;
      }
    }

    return a[l];
  }
};