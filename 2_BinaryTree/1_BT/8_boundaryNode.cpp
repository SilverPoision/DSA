#include <iostream>
using namespace std;

/*
Print all the boundary nodes in the binary tree.Boundary
includes left boundary, leaves, and right boundary in anti
clockwise direction in O(n) Time Complexity Asked in :
Flipkart, OLA, InMobi

*/

class Solution
{
public:
  bool isLeaf(Node *root)
  {
    return (root->left == NULL && root->right == NULL);
  }
  void left(Node *root, vector<int> &ans)
  {
    Node *curr = root->left;

    while (curr)
    {
      if (!isLeaf(curr))
        ans.push_back(curr->data);
      if (curr->left)
        curr = curr->left;
      else
        curr = curr->right;
    }
  }
  void right(Node *root, vector<int> &ans)
  {
    Node *curr = root->right;
    stack<int> st;

    while (curr)
    {
      if (!isLeaf(curr))
        st.push(curr->data);
      if (curr->right)
        curr = curr->right;
      else
        curr = curr->left;
    }

    while (!st.empty())
    {
      ans.push_back(st.top());
      st.pop();
    }
  }
  void leaf(Node *root, vector<int> &ans)
  {
    if (!root)
      return;
    if (isLeaf(root))
    {
      ans.push_back(root->data);
      return;
    }

    leaf(root->left, ans);
    leaf(root->right, ans);
  }
  vector<int> boundary(Node *root)
  {
    vector<int> res;
    if (root == NULL)
      return res;
    if (!isLeaf(root))
      res.push_back(root->data);
    left(root, res);
    leaf(root, res);
    right(root, res);

    return res;
  }
};

int main()
{

  /*
                20
               /  \
             8     22
            / \     \
           14  16     25
              /  \
             9    17
  */

  struct node *root = newNode(1);
  root->left = newNode(2);
  root->right = newNode(3);
  root->left->left = newNode(4);
  root->left->right = newNode(5);
  root->right->left = newNode(6);
  root->right->right = newNode(7);
  root->left->left->left = newNode(8);
  root->left->left->right = newNode(9);
  root->left->right->right = newNode(10);
  root->right->right->left = newNode(11);
  root->left->left->right->left = newNode(12);
  root->left->left->right->right = newNode(13);
  root->right->right->left->left = newNode(14);
  printBoundaryNodes(root);

  return 0;
}

/* Try more Inputs
Case1:
struct node* root = newNode(1);
root->left = newNode(2);
root->right = newNode(3);
root->left->left = newNode(4);
root->left->right = newNode(5);
root->right->left = nnewNode(6);
root->right->right = newNode(7);
root->left->left->left = newNode(8);
root->left->left->right = newNode(9);
root->left->right->right = new Node(10);
root->right->right->left = new Node(11);
root->left->left->right->left = new Node(12);
root->left->left->right->right = new Node(13);
root->right->right->left->left = new Node(14);
printLeftView(root)
expected = [1,2,4,8,12,13,10,6,14,11,7,3]
*/