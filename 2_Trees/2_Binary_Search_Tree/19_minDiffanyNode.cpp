class Solution
{
public:
  // https://www.geeksforgeeks.org/problems/minimum-absolute-difference-in-bst-1665139652/1
  int prev = -1;
  int mini = 1e9;
  void solve(Node *root)
  {
    if (!root)
      return;

    solve(root->left);
    if (prev != -1)
    {
      mini = min(mini, abs(root->data - prev));
    }
    prev = root->data;
    solve(root->right);
  }
  int absolute_diff(Node *root)
  {
    // Your code here
    solve(root);
    return mini;
  }
};