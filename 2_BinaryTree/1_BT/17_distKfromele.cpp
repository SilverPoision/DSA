#include <iostream>
using namespace std;

/*
Find All Nodes Distance K in Binary Tree

Solution:
https://www.geeksforgeeks.org/print-nodes-distance-k-given-node-binary-tree/
*/

node *newnode(int data)
{
  node *temp = new node;
  temp->data = data;
  temp->left = temp->right = NULL;
  return temp;
}

class Solution
{
public:
  // Mark Parent of all nodes;
  void markParent(TreeNode *root, TreeNode *target, map<TreeNode *, TreeNode *> &m)
  {
    queue<TreeNode *> q;
    q.push(root);

    while (!q.empty())
    {
      TreeNode *front = q.front();
      q.pop();

      if (front->left)
      {
        m[front->left] = front;
        q.push(front->left);
      }
      if (front->right)
      {
        m[front->right] = front;
        q.push(front->right);
      }
    }
  }
  vector<int> distanceK(TreeNode *root, TreeNode *target, int k)
  {
    vector<int> ans;
    if (!root)
      return ans;
    map<TreeNode *, TreeNode *> parent;
    markParent(root, target, parent);

    queue<TreeNode *> qt;
    map<TreeNode *, bool> vis;
    int dist = 0;

    qt.push(target);
    vis[target] = true;

    while (!qt.empty())
    {
      int size = qt.size();
      if (dist++ == k)
        break;
      for (int i = 0; i < size; i++)
      {
        auto front = qt.front();
        qt.pop();

        if (front->left && !vis[front->left])
        {
          qt.push(front->left);
          vis[front->left] = true;
        }
        if (front->right && !vis[front->right])
        {
          qt.push(front->right);
          vis[front->right] = true;
        }
        if (parent[front] && !vis[parent[front]])
        {
          qt.push(parent[front]);
          vis[parent[front]] = true;
        }
      }
    }

    while (!qt.empty())
    {
      ans.push_back(qt.front()->val);
      qt.pop();
    }

    return ans;
  }
};

int main()
{

  node *root = newnode(22);
  root->left = newnode(18);
  root->right = newnode(23);
  root->left->left = newnode(14);
  root->left->right = newnode(11);
  root->left->right->left = newnode(9);
  root->left->right->right = newnode(10);
  node *target = root->left->right;
  printkdistanceNode(root, target, 2);
  return 0;
}