class Solution
{
public:
  bool isEvenOddTree(TreeNode *root)
  {
    queue<pair<TreeNode *, int>> q;

    q.push({root, 0});

    while (!q.empty())
    {
      int k = q.size();
      vector<int> temp;
      while (k--)
      {
        auto [node, level] = q.front();
        q.pop();

        if (level & 1)
        {
          if (node->val & 1)
            return false;
          if (temp.size() > 0 && temp.back() <= node->val)
            return false;
        }
        else
        {
          if (!(node->val & 1))
            return false;
          if (temp.size() > 0 && temp.back() >= node->val)
            return false;
        }

        temp.push_back(node->val);

        if (node->left)
          q.push({node->left, level + 1});
        if (node->right)
          q.push({node->right, level + 1});
      }
    }

    return true;
  }
};

//=======================================

class Solution
{
public:
  bool solve(TreeNode *root, int level, unordered_map<int, vector<int>> &hash)
  {
    if (!root)
      return true;

    bool left = solve(root->left, level + 1, hash);
    if (!left)
      return false;

    if (level & 1)
    {
      if (root->val & 1)
        return false;
      if (hash[level].size() > 0)
      {
        if (hash[level].back() <= root->val)
        {
          return false;
        }
      }
    }
    else
    {
      if (!(root->val & 1))
        return false;
      if (hash[level].size() > 0)
      {
        if (hash[level].back() >= root->val)
        {
          return false;
        }
      }
    }
    hash[level].push_back(root->val);
    bool right = solve(root->right, level + 1, hash);
    if (!right)
      return false;

    return right && left;
  }
  bool isEvenOddTree(TreeNode *root)
  {
    unordered_map<int, vector<int>> hash;
    return solve(root, 0, hash);
  }
};