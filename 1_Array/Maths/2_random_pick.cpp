class Solution
{
public:
  // https://leetcode.com/problems/random-pick-index
  // reservoir sampling https://www.youtube.com/watch?v=HXRN8ZfAQOI
  vector<int> arr;
  Solution(vector<int> &nums)
  {
    this->arr = nums;
  }

  int pick(int target)
  {
    int count = 0, picked_ind = 0;

    for (int i = 0; i < this->arr.size(); i++)
    {
      int it = this->arr[i];
      if (it == target)
      {
        count++;
        if ((rand() % count + 1) == count)
        {
          picked_ind = i;
        }
      }
    }
    return picked_ind;
  }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * int param_1 = obj->pick(target);
 */