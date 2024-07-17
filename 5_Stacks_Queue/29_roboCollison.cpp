class Solution
{
public:
  // https://leetcode.com/problems/robot-collisions/submissions/1322949240/?envType=daily-question&envId=2024-07-13
  vector<int> survivedRobotsHealths(vector<int> &p, vector<int> &h, string d)
  {
    vector<int> ind;
    for (int i = 0; i < p.size(); i++)
    {
      ind.push_back(i);
    }

    sort(ind.begin(), ind.end(), [&](int id1, int id2)
         { return p[id1] <= p[id2]; });

    stack<int> st;

    for (auto id : ind)
    {
      if (d[id] == 'R')
      {
        st.push(id);
      }
      else
      {
        while (!st.empty() && h[id] > 0)
        {
          if (h[id] > h[st.top()])
          {
            h[id]--;
            h[st.top()] = 0;
            st.pop();
          }
          else if (h[id] < h[st.top()])
          {
            h[st.top()]--;
            h[id] = 0;
          }
          else
          {
            h[id] = 0;
            h[st.top()] = 0;
            st.pop();
          }
        }
      }
    }

    vector<int> ans;
    for (auto it : h)
      if (it > 0)
        ans.push_back(it);

    return ans;
  }
};