class Solution
{
public:
  // https://www.geeksforgeeks.org/problems/k-closest-elements3619/1
  int big(vector<int> &arr, int &i, int &j, int x)
  {
    int n = arr.size();
    if (j >= n || j < 0)
      return i--;
    if (i >= n || i < 0)
      return j++;

    int a = arr[i];
    int b = arr[j];

    if (abs(a - x) > abs(b - x))
    {
      return j++;
    }
    else if (abs(a - x) < abs(b - x))
    {
      return i--;
    }

    return a > b ? i-- : j++;
  }
  vector<int> printKClosest(vector<int> arr, int n, int k, int x)
  {
    int lb = lower_bound(arr.begin(), arr.end(), x) - arr.begin();
    int ub = upper_bound(arr.begin(), arr.end(), x) - arr.begin();
    lb--;

    vector<int> ans;

    while (k--)
    {
      int mid = big(arr, lb, ub, x);
      ans.push_back(arr[mid]);
    }

    return ans;
  }
};