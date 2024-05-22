class Solution
{ // 124 ms, faster than 5.10%
public:
  // this approach can be used when the matrix is sorted by row and col both
  // but it is not sure that a val in row 1 is less than or greater than val
  // in row 2

  /*
  for ex:
 [[1,5,9],
 [10,11,13],
 [12,13,15]]
  */
  int kthSmallest(vector<vector<int>> &matrix, int k)
  {
    int m = matrix.size(), n = matrix[0].size(), ans; // For general, the matrix need not be a square
    priority_queue<vector<int>, vector<vector<int>>, greater<>> minHeap;
    for (int r = 0; r < min(m, k); ++r)
      minHeap.push({matrix[r][0], r, 0});

    for (int i = 1; i <= k; ++i)
    {
      auto top = minHeap.top();
      minHeap.pop();
      int r = top[1], c = top[2];
      ans = top[0];
      if (c + 1 < n)
        minHeap.push({matrix[r][c + 1], r, c + 1});
    }
    return ans;
  }
};

class Solution
{
public:
  // when you cant do BS on index do it on ans
  int countEleSamllerThanVal(vector<vector<int>> &arr, int val)
  {
    int n = arr.size();
    int cnt = 0;

    for (int i = 0; i < n; i++)
    {
      cnt += upper_bound(arr[i].begin(), arr[i].end(), val) - arr[i].begin();
    }

    return cnt;
  }
  int kthSmallest(vector<vector<int>> &mat, int k)
  {
    int n = mat.size();

    int l = mat[0][0];
    int h = mat[n - 1][n - 1];

    int ans = -1;

    while (l <= h)
    {
      int m = l + (h - l) / 2;

      int cnt = countEleSamllerThanVal(mat, m);
      if (cnt >= k)
      {
        ans = m;
        h = m - 1;
      }
      else
      {
        l = m + 1;
      }
    }

    return ans;
  }
};