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

////
class Solution
{
public:
  vector<int> getNSL(vector<int> &arr)
  {
    int n = arr.size();

    stack<int> st;
    vector<int> ans(n);

    st.push(-1);

    for (int i = 0; i < n; i++)
    {
      int curr = arr[i];
      while (st.size() != 1 && curr <= arr[st.top()])
      {
        st.pop();
      }

      ans[i] = st.top();
      st.push(i);
    }

    return ans;
  }
  vector<int> getNSR(vector<int> &arr)
  {
    int n = arr.size();

    stack<int> st;
    vector<int> ans(n);

    st.push(n);

    for (int i = n - 1; i >= 0; i--)
    {
      int curr = arr[i];
      while (st.size() != 1 && curr <= arr[st.top()])
      {
        st.pop();
      }

      ans[i] = st.top();
      st.push(i);
    }

    return ans;
  }
  int getMaxArea(vector<int> &arr)
  {
    vector<int> left = getNSL(arr);
    vector<int> right = getNSR(arr);
    int maxi = 0;

    for (int i = 0; i < arr.size(); i++)
    {
      int w = (right[i] - left[i] - 1);
      int h = arr[i];
      maxi = max(maxi, w * h);
    }

    return maxi;
  }
  int maximalRectangle(vector<vector<char>> &m)
  {
    int maxi = 0;
    vector<int> arr(m[0].size(), 0);

    for (int i = 0; i < m.size(); i++)
    {
      for (int j = 0; j < m[0].size(); j++)
      {
        if (m[i][j] != '0')
        {
          arr[j] += 1;
        }
        else
        {
          arr[j] = 0;
        }
      }
      maxi = max(maxi, getMaxArea(arr));
    }

    return maxi;
  }
};