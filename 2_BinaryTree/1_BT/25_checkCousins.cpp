#include <bits/stdc++.h>
using namespace std;

/*
Two nodes of a binary tree are cousins if they have
the same depth, but have different parents. We are
given the root of a binary tree with unique values,
and the values x and y of two different nodes in the
tree. Return true if and only if the nodes
corresponding to the values x and y are cousins
*/

// A Binary Tree Node
struct Node
{
  int data;
  struct Node *left, *right;
};

struct NodeInfo
{
  int parent;
  int level;
  int node;
};

// A utility function to create a new
// Binary Tree Node
struct Node *
newNode(int item)
{
  struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
  temp->data = item;
  temp->left = temp->right = NULL;
  return temp;
}

// Returns true if a and b are cousins,
// otherwise false.

void updateLevelandParent(Node *root, NodeInfo &x, NodeInfo &y, int level, int parent)
{
  if (root == NULL)
    return;

  updateLevelandParent(root->left, x, y, level + 1, root->data);
  if (root->data == x.node)
  {
    x.parent = parent;
    x.level = level;
  }
  if (root->data == y.node)
  {
    y.parent = parent;
    y.level = level;
  }
  updateLevelandParent(root->right, x, y, level + 1, root->data);
}

bool isCousinFound(Node *root, int a, int b)
{
  if (root == NULL)
    return false;

  NodeInfo x = {-1, 1, a};
  NodeInfo y = {-1, 1, b};

  updateLevelandParent(root, x, y, 1, -1);

  return x.parent != y.parent && x.level == y.level;
}

int main()
{
  /*
          1
         /  \
        2    3
       / \  / \
      4   5 6  7
           \ \
           15 8
  */

  struct Node *root = newNode(1);
  root->left = newNode(2);
  root->right = newNode(3);
  root->left->left = newNode(4);
  root->left->right = newNode(5);
  root->left->right->right = newNode(15);
  root->right->left = newNode(6);
  root->right->right = newNode(7);
  root->right->left->right = newNode(8);

  isCousinFound(root, 4, 8) ? puts("Yes") : puts("No");

  return 0;
}