struct info
{
  int min, max, size;

  info(int mini, int maxi, int sizi)
  {
    min = mini;
    max = maxi;
    size = sizi;
  }
};

class Solution
{
public:
  /*You are required to complete this method */
  // Return the size of the largest sub-tree which is also a BST
  info post(Node *root)
  {
    if (root == NULL)
    {
      return info(INT_MAX, INT_MIN, 0);
    }

    info l = post(root->left);
    info r = post(root->right);

    if (l.max < root->data && r.min > root->data)
    {
      return info(min(root->data, l.min), max(root->data, r.max), l.size + r.size + 1);
    }

    return info(INT_MIN, INT_MAX, max(l.size, r.size));
  }
  int largestBst(Node *root)
  {
    // Your code here
    return post(root).size;
  }
};