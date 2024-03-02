#include <bits/stdc++.h>
using namespace std;

// Data structure to store a Binary Tree node
struct Node
{
  int key;
  Node *left, *right;

  Node(int key)
  {
    this->key = key;
    this->left = this->right = nullptr;
  }
};

class Solution
{
public:
  vector<int> bottomView(Node *root)
  {
    // Your Code Here
    vector<int> ans;
    map<int, int> m;
    queue<pair<int, Node *>> q;

    q.push({0, root});
    while (!q.empty())
    {
      auto front = q.front();
      q.pop();
      Node *node = front.second;
      int line = front.first;

      m[line] = node->data;

      if (node->left)
        q.push({line - 1, node->left});
      if (node->right)
        q.push({line + 1, node->right});
    }

    for (auto it : m)
    {
      ans.push_back(it.second);
    }

    return ans;
  }
};

int main()
{
  Node *root = nullptr;

  root = new Node(1);
  root->left = new Node(2);
  root->right = new Node(3);
  root->left->right = new Node(4);
  root->right->left = new Node(5);
  root->right->right = new Node(6);
  root->right->left->left = new Node(7);
  root->right->left->right = new Node(8);

  printBottom(root);

  return 0;
}

/* Try more Inputs
Case 1:
result = []
Node root = new Node(20);
root.left = new Node(8);
root.right = new Node(22);
root.left.left = new Node(5);
root.left.right = new Node(3);
root.right.left = new Node(4);
root.right.right = new Node(25);
root.left.right.left = new Node(10);
root.left.right.right = new Node(14);
result = printBottom(root)
expected = [5,10,4,14,25]

Case2:
Node root = new Node(20);
root.left = new Node(8);
root.right = new Node(22);
root.left.left = new Node(5);
root.left.right = new Node(3);
printBottom(root)
expected = [5,3,22]
*/
