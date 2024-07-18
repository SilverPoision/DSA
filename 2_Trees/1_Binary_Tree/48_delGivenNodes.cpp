class Solution
{
public:
  // https://leetcode.com/problems/delete-nodes-and-return-forest/?envType=daily-question&envId=2024-07-17
  unordered_set<int> sd;
  void solve(TreeNode *root, vector<TreeNode *> &ans, TreeNode *par)
  {
    if (!root)
      return;

    solve(root->left, ans, root);
    solve(root->right, ans, root);

    if (sd.count(root->val) > 0)
    {
      if (root->left && sd.count(root->left->val) == 0)
      {
        ans.push_back(root->left);
      }
      if (root->right && sd.count(root->right->val) == 0)
      {
        ans.push_back(root->right);
      }

      if (par)
      {
        if (par->left == root)
        {
          par->left = NULL;
        }
        else
          par->right = NULL;
      }
    }
  }
  vector<TreeNode *> delNodes(TreeNode *root, vector<int> &d)
  {
    unordered_set<int> s(d.begin(), d.end());
    this->sd = s;
    vector<TreeNode *> ans;
    if (sd.count(root->val) == 0)
    {
      ans.push_back(root);
    }
    solve(root, ans, NULL);

    return ans;
  }
};

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
  vector<TreeNode *> delNodes(TreeNode *root, vector<int> &to_delete)
  {
    vector<TreeNode *> rst;
    unordered_set<int> removeSet(to_delete.begin(), to_delete.end());

    root = dfs(root, removeSet, rst);
    if (root)
      rst.push_back(root);
    return rst;
  }

  TreeNode *dfs(TreeNode *root, unordered_set<int> &removeSet, vector<TreeNode *> &rst)
  {
    if (root == nullptr)
      return nullptr;

    root->left = dfs(root->left, removeSet, rst);
    root->right = dfs(root->right, removeSet, rst);

    if (removeSet.count(root->val))
    {
      if (root->left)
        rst.push_back(root->left);
      if (root->right)
        rst.push_back(root->right);
      delete root;
      return nullptr;
    }
    return root;
  }
};