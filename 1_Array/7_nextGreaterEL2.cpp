class Solution
{
public:
  vector<int> nextGreaterElements(vector<int> &arr)
  {
    int n = arr.size();
    stack<int> st;
    vector<int> next(n);

    for (int i = 2 * n - 1; i >= 0; i--)
    {
      int curr = arr[i % n];
      while (!st.empty() && curr >= arr[st.top()])
      {
        st.pop();
      }

      if (i < n)
      {
        if (st.empty())
        {
          next[i] = -1;
        }
        else
        {
          next[i] = arr[st.top()];
        }
      }
      st.push(i % n);
    }
    return next;
  }
};