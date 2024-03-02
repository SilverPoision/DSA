class Solution
{
public:
  // https://leetcode.com/problems/count-the-number-of-incremovable-subarrays-i/
  bool checkInc(vector<int> &temp)
  {
    for (int k = 1; k < temp.size(); k++)
    {
      if (temp[k] <= temp[k - 1])
        return false;
    }

    return true;
  }
  int incremovableSubarrayCount(vector<int> &nums)
  {
    int n = nums.size();
    int cnt = 0;

    for (int i = 0; i < n; i++)
    {
      for (int j = i; j < n; j++)
      {
        vector<int> temp;
        for (int k = 0; k < nums.size(); k++)
        {
          if (k < i || k > j)
          {
            temp.push_back(nums[k]);
          }
        }
        if (checkInc(temp))
        {
          cnt++;
        }
      }
    }

    return cnt;
  }
};