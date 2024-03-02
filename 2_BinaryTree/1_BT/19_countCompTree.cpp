/*
222. Count Complete Tree Nodes
Medium
7K
393
Companies
Given the root of a complete binary tree, return the number of the nodes in the tree.

According to Wikipedia, every level, except possibly the last, is completely filled in a complete binary tree, and all nodes in the last level are as far left as possible. It can have between 1 and 2h nodes inclusive at the last level h.

Design an algorithm that runs in less than O(n) time complexity.
*/

class Solution
{
public:
  int heightLeft(TreeNode *root)
  {
    int height = 0;
    while (root)
    {
      root = root->left;
      height++;
    }
    return height;
  }
  int heightRight(TreeNode *root)
  {
    int height = 0;
    while (root)
    {
      root = root->right;
      height++;
    }
    return height;
  }
  int countNodes(TreeNode *root)
  {
    if (!root)
      return 0;

    int lh = heightLeft(root);
    int rh = heightRight(root);

    if (lh == rh)
      return (1 << lh) - 1;

    return 1 + countNodes(root->left) + countNodes(root->right);
  }
};