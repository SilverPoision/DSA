class Solution
{
public:
  // https://leetcode.com/problems/minimum-operations-to-make-binary-array-elements-equal-to-one-ii/
  int minOperations(vector<int> &nums)
  {
    int n = nums.size();
    int k = 0;

    int cnt = 0;

    for (int i = 0; i < n; i++)
    {
      if ((nums[i] == 0 && (k & 1) == 0) || (nums[i] == 1 && (k & 1) == 1))
      {
        nums[i] = 1;
        k++;
        cnt++;
      }
    }

    return cnt;
  }
};