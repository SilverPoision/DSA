class Solution
{
public:
  // Function to construct binary tree from parent array.
  Node *createTree(vector<int> parent)
  {
    // Your code here
    unordered_map<int, Node *> mp;
    for (int i = 0; i < parent.size(); i++)
    {
      mp[i] = new Node(i);
    }
    Node *root;
    for (int i = 0; i < parent.size(); i++)
    {
      if (parent[i] == -1)
      {
        root = mp[i];
      }
      else
      {
        if (mp[parent[i]]->left == NULL)
          mp[parent[i]]->left = mp[i];
        else
          mp[parent[i]]->right = mp[i];
      }
    }
    return root;
  }
};

class Solution
{
public:
  // Function to construct binary tree from parent array.
  // https://www.geeksforgeeks.org/problems/construct-binary-tree-from-parent-array/1
  int root;
  void build(int i, vector<int> &p, unordered_map<int, Node *> &h)
  {
    if (i == p.size())
      return;

    if (p[i] == -1)
      root = i;
    if (h.find(p[i]) == h.end())
    {
      h[p[i]] = new Node(p[i]);
    }

    Node *n = h.find(i) == h.end() ? new Node(i) : h[i];

    if (h[p[i]]->left == NULL)
    {
      h[p[i]]->left = n;
    }
    else
    {
      h[p[i]]->right = n;
    }
    h[i] = n;

    build(i + 1, p, h);
  }
  Node *createTree(vector<int> parent)
  {
    // Your code here
    unordered_map<int, Node *> hash;

    // Node *root = new Node(0);
    // hash[0] = root;
    build(0, parent, hash);

    return hash[root];
  }
};