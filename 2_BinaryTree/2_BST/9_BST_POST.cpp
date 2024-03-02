class Solution
{
public:
  void insertNode(TreeNode *&root, int val)
  {
    if (val > root->val)
    {
      if (!root->right)
      {
        root->right = new TreeNode(val);
        return;
      }
      insertNode(root->right, val);
    }
    else
    {
      if (!root->left)
      {
        root->left = new TreeNode(val);
        return;
      }
      insertNode(root->left, val);
    }
  }
  TreeNode *bstFromPreorder(vector<int> &preorder)
  {
    TreeNode *root = new TreeNode(preorder[0]);
    for (int i = 1; i < preorder.size(); i++)
    {
      insertNode(root, preorder[i]);
    }

    return root;
  }
};

// Form a bst throught its post and inorder and inroder can be
// genrated from it preorder by sorting the preorder because
// inroder of a bst is just a sorted pre or post order

class Solution
{
public:
  TreeNode *bstFromPreorder(vector<int> &preorder)
  {
    int i = 0;
    return f(preorder, INT_MAX, i);
  }
  TreeNode *f(vector<int> &pre, int bound, int &i)
  {
    if (i == pre.size() || pre[i] > bound) // why this order matters
      return NULL;

    TreeNode *root = new TreeNode(pre[i++]);
    root->left = f(pre, root->val, i);
    root->right = f(pre, bound, i);

    return root;
  }
};