class Solution
{
public:
  // https://leetcode.com/problems/find-bottom-left-tree-value/?envType=daily-question&envId=2024-02-28
  void inorder(TreeNode *root, int &maxL, int &ans, int h)
  {
    if (!root)
      return;
    inorder(root->left, maxL, ans, h + 1);
    if (h > maxL)
    {
      maxL = h;
      ans = root->val;
    }
    inorder(root->right, maxL, ans, h + 1);
  }
  int findBottomLeftValue(TreeNode *root)
  {
    int maxL = -1;
    int ans = -1;
    inorder(root, maxL, ans, 0);

    return ans;
  }
};