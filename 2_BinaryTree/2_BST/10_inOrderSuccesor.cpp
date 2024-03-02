#include <bits/stdc++.h>
using namespace std;

struct Node
{
  int val;
  Node *left;
  Node *right;
  Node(int data)
  {
    val = data;
    left = right = nullptr;
  }
};

bool insertNode(Node *root, int key)
{
  if (root->val == key)
    return false;

  if (root->val > key)
  {
    if (root->left == NULL)
    {
      root->left = new Node(key);
      return true;
    }
    insertNode(root->left, key);
  }
  else
  {
    if (root->right == NULL)
    {
      root->right = new Node(key);
      return true;
    }
    insertNode(root->right, key);
  }

  return false;
}

void inorder(Node *root)
{
  if (root == NULL)
    return;
  inorder(root->left);
  cout << root->val << " ";
  inorder(root->right);
}

Node *inOrderSuccessor(Node *root, Node *p)
{
  Node *suc = NULL;

  while (root != NULL)
  {
    if (root->val <= p->val)
    {
      root = root->right;
    }
    else
    {
      suc = root;
      root = root->left;
    }
  }

  return suc;
}

Node *inOrderPredecessor(Node *root, Node *p)
{
  Node *pred = NULL;

  while (root != NULL)
  {
    if (root->val >= p->val)
    {
      root = root->left;
    }
    else
    {
      pred = root;
      root = root->right;
    }
  }

  return pred;
}

int main()
{
  Node *root = new Node(5);
  insertNode(root, 1);
  insertNode(root, 2);
  insertNode(root, 3);
  insertNode(root, 4);
  insertNode(root, 6);
  insertNode(root, 7);
  insertNode(root, 8);
  insertNode(root, 9);
  insertNode(root, 10);
  Node *p = new Node(8);
  cout << inOrderSuccessor(root, p)->val << endl;
  cout << inOrderPredecessor(root, p)->val << endl;
  return 0;
}