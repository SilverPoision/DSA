class Solution
{
public:
  int widthOfBinaryTree(TreeNode *root)
  {
    if (!root)
      return 0;
    int ans = 0;
    queue<pair<int, TreeNode *>> q;
    q.push({0, root});
    while (!q.empty())
    {
      int mmin = q.front().first;
      int size = q.size();
      int first, last;
      for (int i = 0; i < size; i++)
      {
        TreeNode *f = q.front().second;
        long long int line = (q.front().first - mmin);
        q.pop();
        if (i == 0)
          first = line;
        if (i == size - 1)
          last = line;

        if (f->left)
          q.push({(line * 2 + 1), f->left});
        if (f->right)
          q.push({(line * 2 + 2), f->right});
      }
      ans = max(ans, last - first + 1);
    }

    return ans;
  }
};