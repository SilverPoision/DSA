class Solution
{
public:
  // more optimal
  // https://leetcode.com/problems/number-of-good-leaf-nodes-pairs/
  int ans = 0;
  vector<int> dfs(TreeNode *root, int d)
  {
    if (!root)
      return {0};
    if (!root->left && !root->right)
      return {1};

    vector<int> left = dfs(root->left, d);
    vector<int> right = dfs(root->right, d);

    for (auto it : left)
    {
      for (auto it2 : right)
      {
        if ((it && it2) && it + it2 <= d)
        {
          ans++;
        }
      }
    }

    vector<int> ret;
    for (auto it : left)
    {
      if (it && it + 1 < d)
        ret.push_back(it + 1);
    }
    for (auto it : right)
    {
      if (it && it + 1 < d)
        ret.push_back(it + 1);
    }

    return ret;
  }
  int countPairs(TreeNode *root, int distance)
  {
    dfs(root, distance);
    return ans;
  }
};

class Solution
{
public:
  bool isLeaf(TreeNode *root)
  {
    return !root->left && !root->right;
  }
  void findLeaf(TreeNode *root, vector<TreeNode *> &l, unordered_map<TreeNode *, TreeNode *> &par, TreeNode *p)
  {
    if (!root)
      return;

    if (p)
      par[root] = p;

    findLeaf(root->left, l, par, root);
    findLeaf(root->right, l, par, root);

    if (isLeaf(root))
      l.push_back(root);
  }
  int dfs(TreeNode *root, int k, unordered_map<TreeNode *, TreeNode *> &par, TreeNode *prev)
  {
    if (!root || k < 0)
      return 0;

    if (isLeaf(root))
    {
      return 1;
    }

    int ans = 0;
    if (par[root] && par[root] != prev)
      ans += dfs(par[root], k - 1, par, root);
    if (prev != root->left)
      ans += dfs(root->left, k - 1, par, root);
    if (prev != root->right)
      ans += dfs(root->right, k - 1, par, root);

    return ans;
  }
  int countPairs(TreeNode *root, int k)
  {
    vector<TreeNode *> leaf;
    unordered_map<TreeNode *, TreeNode *> par;

    findLeaf(root, leaf, par, nullptr);

    int cnt = 0;

    for (auto it : leaf)
    {
      cnt += dfs(par[it], k - 1, par, it);
    }

    return cnt / 2;
  }
};

class Solution
{
public:
  bool isLeaf(TreeNode *root)
  {
    if (!root)
      return false;
    if (!root->left && !root->right)
      return true;
    return false;
  }
  void markParent(TreeNode *root, unordered_map<TreeNode *, TreeNode *> &hash, vector<TreeNode *> &l)
  {
    if (!root)
      return;

    if (root->left)
    {
      hash[root->left] = root;
      markParent(root->left, hash, l);
    }
    if (root->right)
    {
      hash[root->right] = root;
      markParent(root->right, hash, l);
    }

    if (!root->left && !root->right)
    {
      l.push_back(root);
    }
  }
  int findLength(TreeNode *root, int k, unordered_map<TreeNode *, bool> hash,
                 unordered_map<TreeNode *, TreeNode *> &parent)
  {
    if (isLeaf(root) && !hash[root])
      return 1;

    hash[root] = true;

    int left = 0, right = 0, up = 0;

    if (root->left && !hash[root->left] && k > 0)
    {
      left = findLength(root->left, k - 1, hash, parent);
    }
    if (root->right && !hash[root->right] && k > 0)
    {
      right = findLength(root->right, k - 1, hash, parent);
    }
    if (parent[root] && !hash[parent[root]] && k > 0)
    {
      up = findLength(parent[root], k - 1, hash, parent);
    }

    return left + right + up;
  }
  int countPairs(TreeNode *root, int dist)
  {
    vector<TreeNode *> leafs;
    unordered_map<TreeNode *, TreeNode *> parent;
    parent[root] = nullptr;
    markParent(root, parent, leafs);

    int ans = 0;

    for (auto it : leafs)
    {
      unordered_map<TreeNode *, bool> hash;
      hash[it] = true;
      cout << ans << " ";
      ans += findLength(it, dist, hash, parent);
    }

    return ans / 2;
  }
};