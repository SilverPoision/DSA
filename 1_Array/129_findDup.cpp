class Solution
{
public:
  // https://www.youtube.com/watch?v=49HrEGt6D2s
  // https://leetcode.com/problems/find-the-duplicate-number/
  int findDuplicate(vector<int> &nums)
  {
    int n = nums.size();

    int slow = 0, fast = 0;

    while (true)
    {
      slow = nums[slow];
      fast = nums[nums[fast]];

      if (slow == fast)
      {
        fast = 0;
        while (slow != fast)
        {
          slow = nums[slow];
          fast = nums[fast];
        }

        return slow;
      }
    }

    return -1;
  }
};