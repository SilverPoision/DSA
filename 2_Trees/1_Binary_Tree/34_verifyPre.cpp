class Solution
{
public:
  // https://leetcode.com/problems/verify-preorder-serialization-of-a-binary-tree/
  bool checkValid(int &i, vector<string> &tree, vector<bool> &vis)
  {
    if (i >= tree.size())
      return false;

    vis[i] = true;

    bool left = true, right = true;

    if (tree[i] != "#")
    {
      left = checkValid(++i, tree, vis);
      right = checkValid(++i, tree, vis);
    }

    return left && right;
  }
  bool isValidSerialization(string preorder)
  {
    vector<string> tree;
    stringstream s(preorder);
    string num;
    while (getline(s, num, ','))
      tree.push_back(num);

    if (tree.size() % 2 == 0)
      return false;
    vector<bool> vis(tree.size(), false);

    int ind = 0;
    if (checkValid(ind, tree, vis) == false)
      return false;

    for (auto it : vis)
      if (!it)
        return false;

    return true;
  }
};

//
class Solution
{
public:
  bool isValidSerialization(string preorder)
  {

    stringstream ss(preorder);
    string node;

    int capacity = 1;

    while (getline(ss, node, ','))
    {
      if (capacity == 0)
      {
        return false;
      }

      if (node == "#")
      {
        capacity--;
      }
      else
      {
        capacity++;
      }
    }

    return capacity == 0;
  }
};