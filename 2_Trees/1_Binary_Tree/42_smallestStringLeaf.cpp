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
  // https://leetcode.com/problems/smallest-string-starting-from-leaf/
  string ans = "";
  void solve(TreeNode *root, string s)
  {
    if (!root)
      return;
    if (!root->left && !root->right)
    {
      s = char(root->val + 'a') + s;
      if (ans == "" || ans > s)
        ans = s;
      return;
    }

    solve(root->left, char(root->val + 'a') + s);
    solve(root->right, char(root->val + 'a') + s);
  }
  string smallestFromLeaf(TreeNode *root)
  {
    solve(root, "");
    return ans;
  }
};