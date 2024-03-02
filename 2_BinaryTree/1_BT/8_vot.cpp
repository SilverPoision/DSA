class Solution
{
public:
  vector<vector<int>> verticalTraversal(TreeNode *root)
  {
    if (!root)
      return {};
    map<int, map<int, multiset<int>>> nodes;
    queue<pair<pair<int, int>, TreeNode *>> q;
    vector<vector<int>> ans;

    q.push({{0, 0}, root});

    while (!q.empty())
    {
      auto front = q.front();
      q.pop();

      int v = front.first.first;
      int level = front.first.second;

      nodes[v][level].insert(front.second->val);

      if (front.second->left)
        q.push({{v - 1, level + 1}, front.second->left});
      if (front.second->right)
        q.push({{v + 1, level + 1}, front.second->right});
    }

    for (auto it : nodes)
    {
      vector<int> temp;
      for (auto i : it.second)
      {
        temp.insert(temp.end(), i.second.begin(), i.second.end());
      }
      ans.push_back(temp);
    }

    return ans;
  }
};