class Solution
{
public:
  TreeNode *f(TreeNode *&root, int val)
  {
    if (!root)
      return NULL;

    if (root->val > val)
    {
      if (root->left == NULL)
      {
        root->left = new TreeNode(val);
        return NULL;
      }
      f(root->left, val);
    }
    else
    {
      if (root->right == NULL)
      {
        root->right = new TreeNode(val);
        return NULL;
      }
      f(root->right, val);
    }
    return NULL;
  }
  TreeNode *insertIntoBST(TreeNode *root, int val)
  {
    if (root == NULL)
      return new TreeNode(val);
    f(root, val);
    return root;
  }
};