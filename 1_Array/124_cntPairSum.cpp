class Solution
{
public:
  // https://www.geeksforgeeks.org/problems/count-pairs-sum-in-matrices4332/1
  bool bs(vector<vector<int>> &mat, int req)
  {
    int n = mat.size();
    int low = 0, high = n * n - 1;

    while (low <= high)
    {
      int mid = (high + low) / 2;

      int row = mid / n;
      int col = mid % n;

      if (mat[row][col] == req)
        return true;

      if (mat[row][col] > req)
      {
        high = mid - 1;
      }
      else
      {
        low = mid + 1;
      }
    }

    return false;
  }

  int countPairs(vector<vector<int>> &mat1, vector<vector<int>> &mat2, int n, int x)
  {
    // Your code goes here
    int cnt = 0;
    for (auto it : mat1)
    {
      for (auto it2 : it)
      {
        int req = x - it2;
        if (bs(mat2, req))
          cnt++;
      }
    }

    return cnt;
  }
};