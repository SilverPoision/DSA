void flat(TreeNode<int> *root, TreeNode<int> *&prev)
{
  if (!root)
    return;
  flat(root->left, prev);
  prev->left = NULL;
  prev->right = root;
  prev = root;
  flat(root->right, prev);
}

TreeNode<int> *flatten(TreeNode<int> *root)
{
  // Write your code here
  TreeNode<int> *dummy = new TreeNode(1);
  TreeNode<int> *prev = dummy;

  flat(root, prev);
  prev->left = nullptr;
  prev->right = nullptr;

  return dummy->right;
}
