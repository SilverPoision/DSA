class Solution
{
public:
  // https://leetcode.com/problems/kth-missing-positive-number/description/
  int findKthPositive(vector<int> &arr, int k)
  {
    int n = arr.size();

    for (int i = 0; i < n; i++)
    {
      if (arr[i] <= k)
        k++;
    }

    return k;
  }
};

class Solution
{
public:
  int findKthPositive(vector<int> &arr, int k)
  {
    int low = 0, high = arr.size() - 1;

    while (low <= high)
    {
      int mid = (low + high) / 2;
      int missing = arr[mid] - (mid + 1); // https://youtu.be/uZ0N_hZpyps?si=T5iXYcjRrgRh_XmC&t=539

      if (missing < k)
      {
        low = mid + 1;
      }
      else
      {
        high = mid - 1;
      }
    }

    // return arr[high]+(k-arr[high] - high+1); //https://youtu.be/uZ0N_hZpyps?si=tFhSJIW66lKuEBnT&t=811
    return high + 1 + k; // derived from the formula
    // return low+k;
  }
};