class Solution
{
public:
  int findMaxArea(vector<int> &arr)
  {
    stack<int> st;
    int maxi = -1e9;

    for (int i = 0; i <= arr.size(); i++)
    {
      while (!st.empty() && (i == arr.size() || arr[i] <= arr[st.top()]))
      {
        int height = arr[st.top()];
        st.pop();
        int width;
        if (st.empty())
          width = i;
        else
          width = i - st.top() - 1;
        maxi = max(maxi, width * height);
      }
      st.push(i);
    }
    return maxi;
  }
  int maximalRectangle(vector<vector<char>> &mat)
  {
    vector<int> arr(mat[0].size(), 0);
    int maxi = 0;
    for (int i = 0; i < mat.size(); i++)
    {
      for (int j = 0; j < mat[0].size(); j++)
      {
        if (mat[i][j] != '0')
        {
          arr[j]++;
        }
        else
        {
          arr[j] = 0;
        }
      }
      maxi = max(maxi, findMaxArea(arr));
    }
    return maxi;
  }
};