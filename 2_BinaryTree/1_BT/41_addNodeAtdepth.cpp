class Solution
{
public:
  // https://leetcode.com/problems/add-one-row-to-tree/?envType=daily-question&envId=2024-04-16
  void solve(TreeNode *root, int val, int depth, int d)
  {
    if (!root)
      return;

    if (d == (depth - 1))
    {
      root->left = new TreeNode(val, root->left, NULL);
      root->right = new TreeNode(val, NULL, root->right);
      return;
    }

    solve(root->left, val, depth, d + 1);
    solve(root->right, val, depth, d + 1);
  }
  TreeNode *addOneRow(TreeNode *root, int val, int depth)
  {
    if (depth == 1)
      return new TreeNode(val, root, NULL);
    solve(root, val, depth, 1);
    return root;
  }
};