class Solution
{
public:
  int maxi = -1e9;
  void f(int i, vector<int> nums, int n)
  {
    if (i >= n)
      return;
    int sum = 0;
    int j = 0;
    for (int k = n - i; k < n - i + n; k++)
    {
      sum += j * nums[k % n];
      j++;
    }
    maxi = max(maxi, sum);
    f(i + 1, nums, n);
  }
  int maxRotateFunction(vector<int> &nums)
  {
    f(0, nums, nums.size());
    return maxi;
  }
};

class Solution
{
public:
  int maxRotateFunction(vector<int> &nums)
  {
    int n = nums.size();
    int f = 0;
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
      sum += nums[i];
      f += i * nums[i];
    }

    int maxi = f;
    for (int i = n - 1; i > 0; i--)
    {
      f = f + sum - n * nums[i];
      maxi = max(f, maxi);
    }
    return maxi;
  }
};