class Solution
{
public:
  // https://leetcode.com/problems/product-of-array-except-self/?envType=daily-question&envId=2024-03-15
  vector<int> productExceptSelf(vector<int> &nums)
  {
    int n = nums.size();

    vector<int> suf(n), ans(n);

    suf[n - 1] = nums[n - 1];

    for (int i = n - 2; i >= 0; i--)
    {
      suf[i] = suf[i + 1] * nums[i];
    }

    int pre = 1;

    for (int i = 0; i < n; i++)
    {
      int s = 1;
      if (i + 1 < n)
        s = suf[i + 1];

      ans[i] = pre * s;

      pre = pre * nums[i];
    }

    return ans;
  }
};

////o(1) SC
class Solution
{
public:
  vector<int> productExceptSelf(vector<int> &nums)
  {
    int n = nums.size();

    vector<int> ans(n);

    int prod = 1;
    int z = 0;
    int idx = -1;

    for (int i = 0; i < n; i++)
    {
      if (nums[i] == 0)
      {
        z++;
        idx = i;
        if (z > 1)
          return ans;
        continue;
      }
      prod *= nums[i];
    }

    if (z == 1)
    {
      ans[idx] = prod;
    }
    else
    {
      for (int i = 0; i < n; i++)
      {
        ans[i] = prod / nums[i];
      }
    }

    return ans;
  }
};