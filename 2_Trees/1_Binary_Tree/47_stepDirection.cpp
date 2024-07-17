class Solution
{
public:
  // https://leetcode.com/problems/step-by-step-directions-from-a-binary-tree-node-to-another/?envType=daily-question&envId=2024-07-16
  static TreeNode *LCA(TreeNode *root, int x, int y)
  {
    if (root == NULL || root->val == x || root->val == y)
      return root;
    TreeNode *l = LCA(root->left, x, y);
    TreeNode *r = LCA(root->right, x, y);
    if (l == NULL)
      return r;
    if (r == NULL)
      return l;
    return root;
  }

  static bool dfs(TreeNode *root, int x, string &path, bool rev = 0)
  {
    if (root == NULL)
      return 0;
    if (root->val == x)
      return 1;

    path += (rev ? 'U' : 'L');
    if (dfs(root->left, x, path, rev))
      return 1;
    path.pop_back();

    path += (rev ? 'U' : 'R');
    if (dfs(root->right, x, path, rev))
      return 1;
    path.pop_back();

    return 0;
  }

  static string getDirections(TreeNode *root, int startValue, int destValue)
  {
    root = LCA(root, startValue, destValue);
    string pathFrom = "", pathTo = "";
    dfs(root, startValue, pathFrom, 1);
    dfs(root, destValue, pathTo);
    return pathFrom + pathTo;
  }
};

auto init = []()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  return 'c';
}();

//
class Solution
{
public:
  bool find(TreeNode *n, int val, string &path)
  {
    if (n->val == val)
      return true;
    if (n->left && find(n->left, val, path))
      path.push_back('L');
    else if (n->right && find(n->right, val, path))
      path.push_back('R');
    return !path.empty();
  }
  string getDirections(TreeNode *root, int startValue, int destValue)
  {
    string s_p, d_p;
    find(root, startValue, s_p);
    find(root, destValue, d_p);
    while (!s_p.empty() && !d_p.empty() && s_p.back() == d_p.back())
    {
      s_p.pop_back();
      d_p.pop_back();
    }
    return string(s_p.size(), 'U') + string(rbegin(d_p), rend(d_p));
  }
};
