class Solution
{
public:
  // https://leetcode.com/problems/find-duplicate-subtrees/
  vector<TreeNode *> ans;
  unordered_map<string, int> hash;
  string dfs(TreeNode *root)
  {
    if (!root)
      return "#";

    string s = to_string(root->val) + "," + dfs(root->left) + "," + dfs(root->right);

    if (hash[s] == 1)
      ans.push_back(root);
    hash[s]++;

    return s;
  }
  vector<TreeNode *> findDuplicateSubtrees(TreeNode *root)
  {
    dfs(root);
    return ans;
  }
};