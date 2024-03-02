class Solution
{
public:
  TreeNode *build(vector<int> &in, int inStart, int inEnd, vector<int> &post, int postStart, int postEnd, map<int, int> &m)
  {
    if (inStart > inEnd || postStart > postEnd)
      return NULL;

    TreeNode *root = new TreeNode(post[postEnd]);
    int inRoot = m[post[postEnd]];
    int numsLeft = inRoot - inStart;

    root->left = build(in, inStart, inRoot - 1, post, postStart, postStart + numsLeft - 1, m);
    root->right = build(in, inRoot + 1, inEnd, post, postStart + numsLeft, postEnd - 1, m);

    return root;
  }
  TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder)
  {
    if (inorder.size() != postorder.size())
      return NULL;
    map<int, int> m;
    int size = inorder.size();

    for (int i = 0; i < size; i++)
    {
      m[inorder[i]] = i;
    }

    TreeNode *root = build(inorder, 0, size - 1, postorder, 0, size - 1, m);
    return root;
  }
};