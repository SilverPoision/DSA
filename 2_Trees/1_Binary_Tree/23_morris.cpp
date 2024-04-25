/*
In-order Morris Traversal:
🌳 1st case: if left is null, print current node and go right
🌳 2nd case: before going left, make right most node on left subtree connected to current node, then go left
🌳 3rd case: if thread is already pointed to current node, then remove the thread
*/

class Solution
{
public:
  vector<int> inorderTraversal(TreeNode *root)
  {
    vector<int> in;
    if (!root)
      return in;
    TreeNode *node = root;

    while (node != NULL)
    {
      if (node->left == NULL)
      {
        in.push_back(node->val);
        node = node->right;
      }
      else
      {
        TreeNode *prev = node->left;
        while (prev->right && prev->right != node)
        {
          prev = prev->right;
        }
        if (prev->right == NULL)
        {
          prev->right = node;
          node = node->left;
        }
        else
        {
          prev->right = NULL;
          in.push_back(node->val);
          node = node->right;
        }
      }
    }
    return in;
  }
};

class Solution
{
public:
  vector<int> preorderTraversal(TreeNode *root)
  {
    vector<int> pre;
    if (!root)
      return pre;

    TreeNode *node = root;
    while (node != NULL)
    {
      if (node->left == NULL)
      {
        pre.push_back(node->val);
        node = node->right;
      }
      else
      {
        TreeNode *prev = node->left;
        while (prev->right && prev->right != node)
        {
          prev = prev->right;
        }
        if (prev->right == NULL)
        {
          prev->right = node;
          pre.push_back(node->val);
          node = node->left;
        }
        else
        {
          prev->right = NULL;
          node = node->right;
        }
      }
    }
    return pre;
  }
};

// reverse the pre to get post