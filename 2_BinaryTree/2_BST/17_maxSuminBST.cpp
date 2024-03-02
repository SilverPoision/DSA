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
struct info
{
  int min, max, maxSum;

  info(int mini, int maxi, int sum)
  {
    this->min = mini;
    this->max = maxi;
    this->maxSum = sum;
  }
};

info f(TreeNode *root, int &maxi)
{
  if (root == NULL)
  {
    return info(INT_MAX, INT_MIN, 0);
  }

  info left = f(root->left, maxi);
  info right = f(root->right, maxi);

  if (left.max < root->val && right.min > root->val)
  {
    maxi = max(maxi, left.maxSum + right.maxSum + root->val);
    return info(min(left.min, root->val), max(right.max, root->val), left.maxSum + right.maxSum + root->val);
  }

  return info(INT_MIN, INT_MAX, 0);
}

class Solution
{
public:
  int maxSumBST(TreeNode *root)
  {
    int res = INT_MIN;
    f(root, res);
    return res < 0 ? 0 : res;
  }
};