class Solution
{
public:
  // https://leetcode.com/problems/global-and-local-inversions/description/
  bool isIdealPermutation(vector<int> &arr)
  {
    // Any number can be placed at i or i+1 or i-1 ot the no of global inversion will be greater
    int n = arr.size();
    for (int i = 0; i < n; i++)
    {
      if (abs(arr[i] - i) > 1)
        return false;
    }

    return true;
  }
};