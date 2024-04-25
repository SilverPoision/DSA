class Solution
{
public:
  void bt(TreeNode *root, vector<char> st, vector<vector<char>> &st1)
  {
    if (!root)
      return;
    if (root->left == NULL && root->right == NULL)
    {
      st.push_back(root->val);
      st1.push_back(st);
      return;
    }

    st.push_back(root->val);
    bt(root->left, st, st1);
    bt(root->right, st, st1);
    st.pop_back();
  }
  vector<string> binaryTreePaths(TreeNode *root)
  {
    vector<string> ans;
    if (!root)
      return ans;

    vector<char> st;
    vector<vector<char>> st1;
    bt(root, st, st1);
    for (auto it : st1)
    {
      string s;
      for (auto it2 : it)
      {
        s += to_string(it2) + "->";
      }
      s.pop_back();
      s.pop_back();
      ans.push_back(s);
    }
    return ans;
  }
};