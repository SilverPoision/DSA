#include <bits/stdc++.h>
using namespace std;

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
  vector<vector<int>> zigzagLevelOrder(TreeNode *root)
  {
    vector<vector<int>> ans;
    if (root == nullptr)
      return ans;
    queue<TreeNode *> q;
    q.push(root);
    bool flag = true;

    while (!q.empty())
    {
      int size = q.size();
      vector<int> temp(size);
      for (int i = 0; i < size; i++)
      {
        TreeNode *front = q.front();
        q.pop();
        int ind = flag ? i : (size - 1 - i);
        temp[ind] = front->val;
        if (front->left != nullptr)
        {
          q.push(front->left);
        }
        if (front->right != nullptr)
        {
          q.push(front->right);
        }
      }
      ans.push_back(temp);
      flag = !flag;
    }
    return ans;
  }
};

int main()
{
  Node *root = new Node(2);
  root->left = new Node(3);
  root->right = new Node(4);
  root->left->left = new Node(8);
  root->left->right = new Node(7);
  root->right->left = new Node(6);
  root->right->right = new Node(5);

  reverseLevelOrder(root);

  return 0;
}

/* Try more Inputs
case1:
Node tree = new Node();
tree->root = new Node(1);
tree->root->left = new Node(2);
tree->root->right = new Node(3);
actual = reverseLevelOrder(tree)
expect = 2 3 1

case2:
Node tree = new Node();
tree->root = new Node(1);
tree->root->left = new Node(2);
tree->root->right = new Node(3);
tree->root->right->left = new Node(-4);
tree->root->right->right = new Node(-5);
expect = -4 -5 2 3 1
*/