class Solution
{
public:
  vector<int> rightSideView(TreeNode *root)
  {
    map<int, int> m;
    vector<int> ans;

    if (!root)
      return ans;
    queue<pair<int, TreeNode *>> q;

    q.push({0, root});
    while (!q.empty())
    {
      auto front = q.front();
      q.pop();
      int line = front.first;
      auto node = front.second;

      m[line] = node->val;

      if (node->left)
        q.push({line + 1, node->left});
      if (node->right)
        q.push({line + 1, node->right});
    }

    for (auto it : m)
    {
      ans.push_back(it.second);
    }

    return ans;
  }
};