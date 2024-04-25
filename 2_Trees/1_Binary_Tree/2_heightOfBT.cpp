#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
  Node *left;
  Node *right;
  int data;
  Node(int d)
  {
    left = right = nullptr;
    data = d;
  }
};

int height(Node *root)
{
  if (root == NULL)
  {
    return 0;
  }

  int depLeft = height(root->left);
  int depRight = height(root->right);

  return 1 + max(depLeft, depRight);
}

int main()
{
  Node *root = new Node(1);
  root->left = new Node(2);
  root->right = new Node(3);
  root->left->left = new Node(4);
  root->left->right = new Node(5);
  root->left->right->left = new Node(9);
  root->right->left = new Node(6);
  root->right->right = new Node(7);
  cout << height(root);
  return 0;
}