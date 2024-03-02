class Solution
{
public:
  int scoreOfParentheses(string s)
  {
    int depth = 0;
    char prev = '(';
    int ans = 0;
    for (auto it : s)
    {
      if (it == '(')
      {
        depth++;
      }
      else
      {
        depth--;
        if (prev == '(')
          ans += pow(2, depth);
      }
      prev = it;
    }

    return ans;
  }
};

class Solution
{
public:
  int scoreOfParentheses(string s)
  {
    stack<int> st;
    int score = 0;
    for (auto it : s)
    {
      if (it == '(')
      {
        st.push(score);
        score = 0;
      }
      else
      {
        score = st.top() + max(2 * score, 1);
        st.pop();
      }
    }

    return score;
  }
};