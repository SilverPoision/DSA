class Solution
{
public:
  // https://www.geeksforgeeks.org/problems/remove-half-nodes/1
  Node *solve(Node *root)
  {
    if (!root)
      return NULL;
    if (!root->right && !root->left)
      return root;

    root->left = solve(root->left);
    root->right = solve(root->right);

    if (!root->right)
      return root->left;
    if (!root->left)
      return root->right;

    return root;
  }
  Node *RemoveHalfNodes(Node *root)
  {
    // code here
    return solve(root);
  }
};