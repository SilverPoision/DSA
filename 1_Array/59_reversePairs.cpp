class Solution
{
public:
  int merge(vector<int> &arr, int low, int high, int mid)
  {
    int i = low, j = mid + 1;

    vector<int> temp;

    int inversion = 0;

    int right = mid + 1;
    for (int left = low; left <= mid; left++)
    {
      while (right <= high && arr[left] > 2 * (long long)arr[right])
      {
        right++;
      }

      inversion += (right - (mid + 1));
    }

    while (i <= mid && j <= high)
    {
      if (arr[i] > arr[j])
      {
        temp.push_back(arr[j++]);
      }
      else
      {
        temp.push_back(arr[i++]);
      }
    }

    while (i <= mid)
    {
      temp.push_back(arr[i++]);
    }
    while (j <= high)
    {
      temp.push_back(arr[j++]);
    }

    for (int ind = low; ind <= high; ind++)
    {
      arr[ind] = temp[ind - low];
    }

    return inversion;
  }
  int mergeSort(vector<int> &arr, int low, int high)
  {
    int inversion = 0;
    if (low < high)
    {
      int mid = (low + high) / 2;

      inversion += mergeSort(arr, low, mid);
      inversion += mergeSort(arr, mid + 1, high);
      inversion += merge(arr, low, high, mid);
    }

    return inversion;
  }
  int reversePairs(vector<int> &nums)
  {
    return mergeSort(nums, 0, nums.size() - 1);
  }
};