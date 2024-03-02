#include <bits/stdc++.h>
using namespace std;

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

int findDiameter(Node *root, int *maxi)
{
  if (root == NULL)
    return 0;

  int lHeight = findDiameter(root->left, maxi);
  int rHeight = findDiameter(root->right, maxi);

  *maxi = max(*maxi, (lHeight + rHeight));

  return 1 + max(lHeight, rHeight);
}

int main()
{
  Node *root = nullptr;

  root = new Node(1);
  root->left = new Node(2);
  root->right = new Node(3);
  root->left->left = new Node(4);
  root->left->right = new Node(5);

  int maxi = 0;
  findDiameter(root, &maxi);
  cout << "The diameter of the tree is " << maxi;

  return 0;
}

/* Try more Inputs
Case 1:
BinaryTree tree = new BinaryTree();
tree.root = new Node(12);
tree.root.left = new Node(10);
tree.root.right = new Node(30);
tree.root.right.left = new Node(25);
tree.root.right.right = new Node(40);
printLeftView(root)
expected = [12,10,25]

Case2:
BinaryTree root = newNode(10);
root.left = newNode(12);
root.right = newNode(3);
root.left.right = newNode(4);
root.right.left = newNode(5);
root.right.left.right = newNode(6);
root.right.left.right.left = newNode(18);
root.right.left.right.right = newNode(7);
printLeftView(root)
expected = [10,12,4,6,18]
*/

/*
int height(Node *root)
{
  if (root == NULL)
  {
    return 0;
  }

  return 1 + max(height(root->left), height(root->right));
}

int findDiameter(Node *root)
{
  if (root == NULL)
    return 0;

  int heightL = height(root->left);
  int heightR = height(root->right);

  int diameterL = findDiameter(root->left);
  int diameterR = findDiameter(root->right);

  return max(heightL + heightR + 1, max(diameterL, diameterR));
}
*/