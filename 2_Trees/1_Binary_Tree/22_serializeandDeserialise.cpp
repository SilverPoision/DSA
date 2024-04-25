string serialize(TreeNode *root)
{
  if (!root)
    return "";

  string s = "";

  queue<TreeNode *> q;
  q.push(root);
  while (!q.empty())
  {
    TreeNode *front = q.front();
    q.pop();
    if (front == NULL)
      s.append("#,");
    else
      s.append(to_string(front->val) + ',');

    if (front != NULL)
    {
      q.push(front->left);
      q.push(front->right);
    }
  }

  return s;
}

// Decodes your encoded data to tree.
TreeNode *deserialize(string data)
{
  if (data.size() == 0)
    return NULL;
  stringstream s(data);
  string str;
  getline(s, str, ',');
  TreeNode *root = new TreeNode(stoi(str));
  queue<TreeNode *> q;
  q.push(root);

  while (!q.empty())
  {
    TreeNode *front = q.front();
    q.pop();

    getline(s, str, ',');
    if (str == "#")
      front->left = NULL;
    else
    {
      TreeNode *left = new TreeNode(stoi(str));
      front->left = left;
      q.push(front->left);
    }

    getline(s, str, ',');
    if (str == "#")
      front->right = NULL;
    else
    {
      TreeNode *right = new TreeNode(stoi(str));
      front->right = right;
      q.push(front->right);
    }
  }
  return root;
};