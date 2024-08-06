class BST
{
public:
  int mini, maxi;
  bool isBST;
  BST(int mini, int maxi, bool isBST)
  {
    this->mini = mini;
    this->maxi = maxi;
    this->isBST = isBST;
  }
};

class Solution
{
public:
  // https://www.geeksforgeeks.org/problems/check-for-bst/1
  //  Function to check whether a Binary Tree is BST or not.
  BST solve(Node *root)
  {
    if (!root)
      return BST(INT_MAX, INT_MIN, true);

    BST left = solve(root->left);
    BST right = solve(root->right);

    if (!left.isBST || !right.isBST)
      return BST(INT_MIN, INT_MAX, false);

    if (left.maxi < root->data && right.mini > root->data)
    {
      return BST(min(left.mini, root->data), max(right.maxi, root->data), true);
    }

    return BST(INT_MIN, INT_MAX, false);
  }
  bool isBST(Node *root)
  {
    // Your code here
    return solve(root).isBST;
  }
};

class Solution
{
public:
  int isItBST(struct Node *node, int min, int max)
  {
    if (node == NULL)
      return 1;
    if (node->data < min || node->data > max)
      return 0;
    return isItBST(node->left, min, node->data - 1) &&
           isItBST(node->right, node->data + 1, max);
  }
  bool isBST(Node *root)
  {
    return isItBST(root, INT_MIN, INT_MAX);
  }
};