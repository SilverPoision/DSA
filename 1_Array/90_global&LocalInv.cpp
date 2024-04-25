class Solution
{
public:
  // https://leetcode.com/problems/global-and-local-inversions/
  /*
  The problem asks us to find whether the number of global inversions are equal to local
   inversion.And we know all local inversion are global. Why? .Because local inversions
   are basically gobal with a distance as one between them.So if we can find at least one
   global inversion which is not local our job is done and we can eliminate by returning
   false.And since we are maintaining the maximum value all the cases will be covered in it.
  */
  bool isIdealPermutation(vector<int> &A)
  {
    int cmax = 0, n = A.size();
    for (int i = 0; i < n - 2; ++i)
    {
      cmax = max(cmax, A[i]);
      if (cmax > A[i + 2])
        return false;
    }
    return true;
  }
};