class Solution
{
public:
  int path(TreeNode *node, int *maxi)
  {
    if (node == nullptr)
      return 0;

    int left = max(0, path(node->left, maxi));
    int right = max(0, path(node->right, maxi));

    *maxi = max(*maxi, (left + right + node->val));

    return node->val + max(left, right);
  }
  int maxPathSum(TreeNode *root)
  {
    int maxi = -1e9;
    path(root, &maxi);
    return maxi;
  }
};
