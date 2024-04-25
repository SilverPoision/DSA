class Solution
{
public:
  bool f(TreeNode *root, long min, long max)
  {
    if (root == NULL)
      return true;

    bool left = f(root->left, min, root->val);
    bool right = f(root->right, root->val, max);

    if (root->val < max && root->val > min)
    {
      return left && right;
    }
    else
    {
      return false;
    }
  }
  bool isValidBST(TreeNode *root)
  {
    return f(root, LONG_MIN, LONG_MAX);
  }
};