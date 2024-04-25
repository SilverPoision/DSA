class BSTIterator
{
  bool reverse = true;
  stack<TreeNode *> st;
  void pushAll(TreeNode *root)
  {
    while (root)
    {
      st.push(root);
      if (reverse)
      {
        root = root->right;
      }
      else
      {
        root = root->left;
      }
    }
  }

public:
  bool hasNext()
  {
    return !st.empty();
  }

  BSTIterator(TreeNode *root, bool isReverse)
  {
    reverse = isReverse;
    pushAll(root);
  }

  int next()
  {
    TreeNode *in = st.top();
    st.pop();
    if (!reverse)
    {
      pushAll(in->right);
    }
    else
    {
      pushAll(in->left);
    }
    return in->val;
  }
};

class Solution
{
public:
  bool findTarget(TreeNode *root, int k)
  {
    if (!root)
      return false;
    BSTIterator l(root, false);
    BSTIterator r(root, true);

    int i = l.next();
    int j = r.next();
    while (i < j)
    {
      if (i + j == k)
      {
        return true;
      }
      else if (i + j > k)
      {
        j = r.next();
      }
      else
      {
        i = l.next();
      }
    }
    return false;
  }
};