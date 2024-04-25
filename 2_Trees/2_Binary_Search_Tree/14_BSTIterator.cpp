class BSTIterator
{
  void pushAll(TreeNode *temp)
  {
    while (temp != NULL)
    {
      st.push(temp);
      temp = temp->left;
    }
  }
  stack<TreeNode *> st;

public:
  BSTIterator(TreeNode *root)
  {
    pushAll(root);
  }

  int next()
  {
    TreeNode *t = st.top();
    st.pop();
    if (t->right != NULL)
    {
      pushAll(t->right);
    }
    return t->val;
  }

  bool hasNext()
  {
    return !st.empty();
  }
};
