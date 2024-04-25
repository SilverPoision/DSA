#include <iostream>
using namespace std;

/*
Convert BT to DLL such that the left pointer of the node should
be pointing to the previous node in the doubly linked list, and
the right pointer should be pointing to the next node in the
doubly linked list in Time Complexity O(n) and Space O(Height)
Asked in : Amazon, Microsoft, Flipkart, WalmartLabs
*/

// Data structure to store a Binary Tree node
struct Node
{
  int data;
  Node *left, *right;

  Node(int data)
  {
    this->data = data;
    this->left = this->right = nullptr;
  }
};

// in-place convert given Binary Tree to a Doubly Linked List
class Solution
{
public:
  TreeNode *prev = NULL;
  void flatten(TreeNode *root)
  {
    if (!root)
      return;

    flatten(root->right);
    flatten(root->left);

    root->right = prev;
    root->left = NULL;
    prev = root;
  }
};

class Solution
{
public:
  TreeNode *prev = NULL;
  void flatten(TreeNode *root)
  {
    if (!root)
      return;

    stack<TreeNode *> st;
    st.push(root);
    while (!st.empty())
    {
      auto curr = st.top();
      st.pop();

      if (curr->right)
        st.push(curr->right);
      if (curr->left)
        st.push(curr->left);

      if (!st.empty())
      {
        curr->right = st.top();
      }
      curr->left = NULL;
    }
  }
};

// Morris
class Solution
{
public:
  void flatten(TreeNode *root)
  {
    if (!root)
      return;

    TreeNode *curr = root;

    while (curr != NULL)
    {
      if (curr->left != NULL)
      {
        TreeNode *prev = curr->left;
        while (prev->right != NULL)
        {
          prev = prev->right;
        }

        prev->right = curr->right;
        curr->right = curr->left;
        curr->left = NULL;
      }
      curr = curr->right;
    }
  }
};
