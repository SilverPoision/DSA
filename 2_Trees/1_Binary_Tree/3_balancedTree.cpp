/*
For this problem, a height-balanced binary tree is defined as: a
binary tree in which the left and right subtrees of every node
differ in height by no more than 1
*/

class Solution
{
public:
  int check(TreeNode *root)
  {
    if (root == NULL)
      return 0;

    int cl = check(root->left);
    if (cl == -1)
      return -1;
    int rl = check(root->right);
    if (rl == -1)
      return -1;

    if (abs(cl - rl) > 1)
      return -1;

    return 1 + max(cl, rl);
  }
  bool isBalanced(TreeNode *root)
  {
    return check(root) == -1 ? false : true;
  }
};
