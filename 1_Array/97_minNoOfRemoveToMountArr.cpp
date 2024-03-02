// Optimal
class Solution
{
public:
  // https://leetcode.com/problems/minimum-number-of-removals-to-make-mountain-array/
  void lis(vector<int> &arr, vector<int> &left)
  {
    int n = arr.size();
    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < i; j++) // notice the loop terminating conditions
      {
        if (arr[i] > arr[j] && left[j] + 1 > left[i])
        {
          left[i] = left[j] + 1;
        }
      }
    }
  }
  int minimumMountainRemovals(vector<int> &arr)
  {
    int n = arr.size();
    vector<int> left(n, 1), right(n, 1);

    lis(arr, left);
    reverse(arr.begin(), arr.end());
    lis(arr, right);
    reverse(right.begin(), right.end());

    int ans = 1;
    for (int i = 0; i < n; i++)
    {
      if (left[i] == 1 || right[i] == 1)
        continue;
      ans = max(ans, left[i] + right[i] - 1);
    }

    return n - ans;
  }
};

class Solution
{
  // TLE
public:
  bool checkMountain(vector<int> &arr)
  {
    int i = 1;
    int n = arr.size();
    while (i < n && arr[i] > arr[i - 1])
    {
      i++;
    }
    if (i == 1 || i == n)
      return false;
    while (i < n && arr[i] < arr[i - 1])
    {
      i++;
    }
    return i == n;
  }
  int f(int i, vector<int> &arr, vector<int> out)
  {
    if (i == arr.size())
    {
      if (checkMountain(out))
      {
        return (arr.size() - out.size());
      }
      return 1e9;
    }

    out.push_back(arr[i]);
    int take = f(i + 1, arr, out);
    out.pop_back();
    int notTake = f(i + 1, arr, out);

    return min(take, notTake);
  }
  int minimumMountainRemovals(vector<int> &nums)
  {
    vector<int> out;
    if (checkMountain(nums))
      return 0;
    return f(0, nums, out);
  }
};
