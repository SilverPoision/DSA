class Solution
{
public:
  bool isSafe(vector<vector<int>> &m, int i, int j, vector<vector<bool>> &vis)
  {
    if (i >= 0 && j >= 0 && i < m.size() && j < m.size() && m[i][j] == 1 && !vis[i][j])
    {
      return true;
    }
    return false;
  }
  void helper(int i, int j, vector<vector<int>> &m, vector<string> &ans, string &st, vector<vector<bool>> &vis)
  {
    if (i == m.size() - 1 && j == m.size() - 1)
    {
      ans.push_back(st);
      return;
    }

    vis[i][j] = true;

    if (isSafe(m, i - 1, j, vis))
    {
      st += "U";
      helper(i - 1, j, m, ans, st, vis);
      st.pop_back();
    }
    if (isSafe(m, i + 1, j, vis))
    {
      st += "D";
      helper(i + 1, j, m, ans, st, vis);
      st.pop_back();
    }
    if (isSafe(m, i, j - 1, vis))
    {
      st += "L";
      helper(i, j - 1, m, ans, st, vis);
      st.pop_back();
    }
    if (isSafe(m, i, j + 1, vis))
    {
      st += "R";
      helper(i, j + 1, m, ans, st, vis);
      st.pop_back();
    }
    vis[i][j] = false;
  }
  vector<string> findPath(vector<vector<int>> &m, int n)
  {
    // Your code goes here
    vector<string> ans;
    vector<vector<bool>> vis(n, vector<bool>(n, false));
    string st = "";
    if (m[0][0] == 1)
      helper(0, 0, m, ans, st, vis);
    else
      return ans;
    sort(ans.begin(), ans.end());
    return ans;
  }
};