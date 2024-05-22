class Solution
{
public:
  // https://leetcode.com/problems/distribute-coins-in-binary-tree/description/?envType=daily-question&envId=2024-05-18
  int ans = 0;
  int solve(TreeNode *root)
  {
    if (!root)
      return 0;

    int l = solve(root->left);
    int r = solve(root->right);

    ans += abs(l) + abs(r);

    return root->val - 1 + l + r;
  }
  int distributeCoins(TreeNode *root)
  {
    solve(root);
    return ans;
  }
};