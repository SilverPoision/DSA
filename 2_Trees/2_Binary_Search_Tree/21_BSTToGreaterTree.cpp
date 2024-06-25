class Solution
{
public:
  // https://leetcode.com/problems/binary-search-tree-to-greater-sum-tree/
  int add = 0;
  void solve(TreeNode *root)
  {
    if (!root)
      return;

    solve(root->right);
    root->val += add;
    add = root->val;
    solve(root->left);
  }
  TreeNode *bstToGst(TreeNode *root)
  {
    solve(root);
    return root;
  }
};

class Solution
{
public:
  int solve(TreeNode *root, int add)
  {
    if (!root)
      return add;
    if (!root->left && !root->right)
    {
      root->val += add;
      return root->val;
    }

    root->val += solve(root->right, add);
    return solve(root->left, root->val);
  }
  TreeNode *bstToGst(TreeNode *root)
  {
    solve(root, 0);
    return root;
  }
};

// Optimal
class Solution
{
public:
  TreeNode *bstToGst(TreeNode *root)
  {
    if (!root)
      return root;

    TreeNode *node = root;
    int g = 0;

    while (node != NULL)
    {
      if (node->right == NULL)
      {
        g += node->val;
        node->val = g;
        node = node->left;
      }
      else
      {
        TreeNode *prev = node->right;
        while (prev->left && prev->left != node)
        {
          prev = prev->left;
        }

        if (prev->left == NULL)
        {
          prev->left = node;
          node = node->right;
        }
        else
        {
          g += node->val;
          node->val = g;
          prev->left = NULL;
          node = node->left;
        }
      }
    }

    return root;
  }
};