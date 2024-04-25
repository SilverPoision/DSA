class Solution
{
public:
  TreeNode *helper(TreeNode *root, int key)
  {
    if (root->left == NULL)
      return root->right;
    if (root->right == NULL)
      return root->left;

    TreeNode *right = root->right;
    TreeNode *leftMost = findLastLeft(root->right);
    leftMost->left = root->left;
    return right;
  }
  TreeNode *findLastLeft(TreeNode *root)
  {
    if (root->left == NULL)
      return root;

    return findLastLeft(root->left);
  }
  TreeNode *deleteNode(TreeNode *root, int key)
  {
    if (root == NULL)
      return NULL;
    if (root->val == key)
      return helper(root, key);
    TreeNode *node = root;
    while (root != NULL)
    {
      if (root->val < key)
      {
        if (root->right != NULL && root->right->val == key)
        {
          root->right = helper(root->right, key);
        }
        else
        {
          root = root->right;
        }
      }
      else
      {
        if (root->left != NULL && root->left->val == key)
        {
          root->left = helper(root->left, key);
        }
        else
        {
          root = root->left;
        }
      }
    }
    return node;
  }
};