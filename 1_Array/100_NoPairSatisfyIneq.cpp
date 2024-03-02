class Solution
{
  // https://leetcode.com/problems/number-of-pairs-satisfying-inequality/
public:
  long long res = 0;
  int dif;

  void merge(int l, int r, int mid, vector<int> &nums)
  {
    int i = l, j = mid + 1, idx = 0;

    while (i <= mid && j <= r)
    {
      if (nums[i] <= nums[j] + dif)
      {
        res += r - j + 1;
        i++;
      }
      else
      {
        j++;
      }
    }

    i = l, j = mid + 1;
    vector<int> temp(r - l + 1);
    while (i <= mid && j <= r)
    {
      if (nums[i] > nums[j])
      {
        temp[idx++] = nums[j++];
      }
      else
      {
        temp[idx++] = nums[i++];
      }
    }

    while (i <= mid)
      temp[idx++] = nums[i++];
    while (j <= r)
      temp[idx++] = nums[j++];

    idx = 0;
    for (int k = l; k <= r; k++, idx++)
      nums[k] = temp[idx];
  }

  void mergeSort(int start, int end, vector<int> &nums)
  {
    if (start >= end)
      return;

    int mid = start + (end - start) / 2;

    mergeSort(start, mid, nums);
    mergeSort(mid + 1, end, nums);
    merge(start, end, mid, nums);
  }
  long long numberOfPairs(vector<int> &nums1, vector<int> &nums2, int diff)
  {
    dif = diff;
    int n = nums1.size();
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
    {
      nums[i] = nums1[i] - nums2[i];
    }
    mergeSort(0, n - 1, nums);
    return res;
  }
};

// Same idea as above
class Solution
{
public:
  long long ans = 0;
  void solve(int l, int r, vector<int> &arr, int diff)
  {
    if (l >= r)
      return;
    int mid = l + (r - l) / 2;
    solve(l, mid, arr, diff);
    solve(mid + 1, r, arr, diff);
    int start = l, right = mid + 1;
    while (start <= mid && right <= r)
    {
      if (arr[start] <= arr[right] + diff)
      {
        ans += (r + 1 - right);
        start++;
      }
      else
        right++;
    }
    sort(arr.begin() + l, arr.begin() + r + 1);
  }
  long long numberOfPairs(vector<int> &nums1, vector<int> &nums2, int diff)
  {
    int n = nums1.size();
    for (int i = 0; i < n; i++)
      nums1[i] -= nums2[i];
    solve(0, n - 1, nums1, diff);
    return ans;
  }
};