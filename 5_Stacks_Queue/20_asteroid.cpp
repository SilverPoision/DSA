vector<int> collidingAsteroids(vector<int> &as)
{
  //    Write your code here.
  stack<int> st;
  for (auto it : as)
  {
    st.push(it);
    while (st.size() > 1 && st.top() <= 0)
    {
      int top = st.top();
      st.pop();
      int bottom = st.top();
      st.pop();

      if (top <= 0 && bottom <= 0)
      {
        st.push(bottom);
        st.push(top);
        break;
      }

      if (abs(top) > abs(bottom))
        st.push(top);
      else if (abs(top) < abs(bottom))
        st.push(bottom);
    }
  }

  int size = st.size();
  vector<int> ans(size);
  size--;

  while (!st.empty())
  {
    ans[size--] = st.top();
    st.pop();
  }

  return ans;
}