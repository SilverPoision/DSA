// https://leetcode.com/problems/sum-root-to-leaf-numbers/?envType=daily-question&envId=2024-04-15
class Solution
{
public:
  int sum = 0;
  void solve(TreeNode *root, int num)
  {
    if (!root)
      return;
    if (!root->left && !root->right)
    {
      sum += num * 10 + root->val;
      return;
    }

    solve(root->left, num * 10 + root->val);
    solve(root->right, num * 10 + root->val);
  }
  int sumNumbers(TreeNode *root)
  {
    solve(root, 0);
    return sum;
  }
};