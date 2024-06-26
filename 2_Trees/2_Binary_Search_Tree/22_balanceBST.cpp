class Solution
{
public:
  // can also be solved by dsw algo
  // https://leetcode.com/problems/balance-a-binary-search-tree/
  // https://www.youtube.com/watch?v=8d9tOlk7g9w&t=1156s
  void iterate(TreeNode *root, vector<int> &v)
  {
    if (!root)
      return;

    iterate(root->left, v);
    v.push_back(root->val);
    iterate(root->right, v);
  }

  TreeNode *solve(vector<int> &v, int l, int r)
  {
    if (l > r)
      return nullptr;

    int mid = (l + r) / 2;
    TreeNode *root = new TreeNode(v[mid]);

    root->left = solve(v, l, mid - 1);
    root->right = solve(v, mid + 1, r);

    return root;
  }

  TreeNode *balanceBST(TreeNode *root)
  {
    vector<int> v;
    iterate(root, v);

    return solve(v, 0, v.size() - 1);
  }
};