/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
public:
  // https://leetcode.com/problems/delete-leaves-with-a-given-value/
  bool isLeaf(TreeNode *root)
  {
    return !root->left && !root->right;
  }
  void solve(TreeNode *root, int target)
  {
    if (!root)
      return;

    solve(root->left, target);
    solve(root->right, target);

    if (root->left && isLeaf(root->left) && root->left->val == target)
    {
      root->left = NULL;
    }
    if (root->right && isLeaf(root->right) && root->right->val == target)
    {
      root->right = NULL;
    }
  }
  TreeNode *removeLeafNodes(TreeNode *root, int target)
  {
    solve(root, target);

    if (isLeaf(root) && root->val == target)
    {
      return NULL;
    }

    return root;
  }
};

class Solution
{
public:
  TreeNode *removeLeafNodes(TreeNode *root, int target)
  {
    if (!root)
      return NULL;

    if (!root->left && !root->right)
    {
      if (root->val == target)
        return NULL;
      else
        root;
    }

    root->left = removeLeafNodes(root->left, target);
    root->right = removeLeafNodes(root->right, target);

    if (root->val == target && !root->left && !root->right)
      return NULL;

    return root;
  }
};