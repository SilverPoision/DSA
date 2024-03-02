class Solution
{
public:
  // finding the root by preorder and then finding the left and right tree in inorder
  TreeNode *build(vector<int> &pre, int preStart, int preEnd, vector<int> &in, int inStart, int inEnd, map<int, int> &m)
  {
    if (preStart > preEnd || inStart > inEnd)
      return NULL;

    TreeNode *root = new TreeNode(pre[preStart]);

    int inRoot = m[pre[preStart]];
    int si = inRoot - inStart; // nums left

    root->left = build(pre, preStart + 1, preStart + si, in, inStart, inRoot - 1, m);
    root->right = build(pre, preStart + si + 1, preEnd, in, inRoot + 1, inEnd, m);

    return root;
  }
  TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
  {
    map<int, int> m;
    int size = inorder.size();
    for (int i = 0; i < size; i++)
    {
      m[inorder[i]] = i;
    }
    TreeNode *root = build(preorder, 0, size - 1, inorder, 0, size - 1, m);

    return root;
  }
};