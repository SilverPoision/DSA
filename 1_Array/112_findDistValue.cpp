class Solution
{
public:
  int findTheDistanceValue(vector<int> &arr1, vector<int> &arr2, int d)
  {
    int cnt = 0;
    sort(arr2.begin(), arr2.end());

    for (auto it : arr1)
    {
      int low = 0;
      int high = arr2.size() - 1;
      cnt++;
      while (low <= high)
      {
        int mid = (low + high) / 2;

        if (abs(arr2[mid] - it) <= d)
        {
          cnt--;
          break;
        }

        if (arr2[mid] < it)
        {
          low = mid + 1;
        }
        else
        {
          high = mid - 1;
        }
      }
    }

    return cnt;
  }
};