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
  // https://leetcode.com/problems/trim-a-binary-search-tree/
  TreeNode *trim(TreeNode *root, int low, int high)
  {
    if (!root)
      return root;

    if (root->val < low)
      return trim(root->right, low, high);
    if (root->val > high)
      return trim(root->left, low, high);

    root->left = trim(root->left, low, high);
    root->right = trim(root->right, low, high);

    return root;
  }
  TreeNode *trimBST(TreeNode *root, int low, int high)
  {
    return trim(root, low, high);
  }
};