class Solution
{
public:
  vector<int> prevSmallerEle(vector<int> &arr)
  {
    stack<int> st;
    vector<int> next(arr.size());

    for (int i = 0; i < arr.size(); i++)
    {
      int curr = arr[i];
      while (!st.empty() && curr <= arr[st.top()])
      {
        st.pop();
      }
      if (st.empty())
      {
        next[i] = -1;
      }
      else
      {
        next[i] = st.top();
      }
      st.push(i);
    }

    return next;
  }
  vector<int> nextSmallerEle(vector<int> &arr)
  {
    stack<int> st;
    vector<int> next(arr.size());

    for (int i = arr.size() - 1; i >= 0; i--)
    {
      int curr = arr[i];
      while (!st.empty() && curr <= arr[st.top()])
      {
        st.pop();
      }
      if (st.empty())
      {
        next[i] = arr.size();
      }
      else
      {
        next[i] = st.top();
      }
      st.push(i);
    }

    return next;
  }
  int largestRectangleArea(vector<int> &heights)
  {
    vector<int> next = nextSmallerEle(heights);
    vector<int> prev = prevSmallerEle(heights);

    int maxi = -1e9;
    for (int i = 0; i < heights.size(); i++)
    {
      maxi = max(((next[i] - prev[i] - 1) * heights[i]), maxi);
    }
    return maxi;
  }
};

// Optimal
class Solution
{
public:
  int largestRectangleArea(vector<int> &arr)
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
};