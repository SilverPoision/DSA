class Solution
{
public:
  // https://leetcode.com/problems/squares-of-a-sorted-array/?envType=daily-question&envId=2024-03-02
  vector<int> sortedSquares(vector<int> &nums)
  {
    int n = nums.size();
    int i = 0, j = 0;

    vector<int> ans;

    while (i < n && nums[i] < 0)
    {
      i++;
    }

    j = i - 1;

    while (i < n && j >= 0)
    {
      if (nums[i] < abs(nums[j]))
      {
        ans.push_back(nums[i] * nums[i]);
        i++;
      }
      else
      {
        ans.push_back(nums[j] * nums[j]);
        j--;
      }
    }

    while (i < n)
    {
      ans.push_back(nums[i] * nums[i]);
      i++;
    }
    while (j >= 0)
    {
      ans.push_back(nums[j] * nums[j]);
      j--;
    }
    return ans;
  }
};

class Solution
{
public:
  // same
  vector<int> sortedSquares(vector<int> &nums)
  {
    int i = 0, j = nums.size() - 1, k = nums.size() - 1;
    vector<int> ans(nums.size());
    while (i <= j)
    {
      if (abs(nums[i]) < abs(nums[j]))
      {
        ans[k--] = nums[j] * nums[j];
        j--;
      }
      else
      {
        ans[k--] = nums[i] * nums[i];
        i++;
      }
    }
    return ans;
  }
};