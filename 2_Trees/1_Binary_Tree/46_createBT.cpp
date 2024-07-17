class Solution
{
public:
  TreeNode *createBinaryTree(vector<vector<int>> &desc)
  {
    unordered_map<int, TreeNode *> hash;
    unordered_set<int> child;

    for (auto it : desc)
    {
      int r = it[0];
      int c = it[1];
      int l = it[2];
      if (hash.find(r) == hash.end())
      {
        TreeNode *node = new TreeNode(r);
        hash[r] = node;
      }
      if (hash.find(c) == hash.end())
      {
        TreeNode *node = new TreeNode(c);
        hash[c] = node;
      }

      if (l)
      {
        hash[r]->left = hash[c];
      }
      else
      {
        hash[r]->right = hash[c];
      }

      child.insert(c);
    }

    for (auto it : desc)
    {
      if (child.find(it[0]) == child.end())
        return hash[it[0]];
    }

    return NULL;
  }
};

class Solution
{
public:
  TreeNode *build(map<pair<int, bool>, int> &h, int r)
  {
    TreeNode *root = new TreeNode(r);

    if (h.find({r, 1}) != h.end())
    {
      root->left = build(h, h[{r, 1}]);
    }
    if (h.find({r, 0}) != h.end())
    {
      root->right = build(h, h[{r, 0}]);
    }

    return root;
  }
  TreeNode *createBinaryTree(vector<vector<int>> &desc)
  {
    unordered_map<int, bool> hash;
    map<pair<int, bool>, int> h;

    for (auto it : desc)
    {
      if (hash.find(it[0]) == hash.end())
        hash[it[0]] = false;
      hash[it[1]] = true;
      h[{it[0], it[2]}] = it[1];
    }

    int r = -1;
    for (auto it : hash)
      if (!it.second)
        r = it.first;

    return build(h, r);
  }
};