#include <bits/stdc++.h>

BinaryTreeNode<int> *markParents(map<BinaryTreeNode<int> *, BinaryTreeNode<int> *> &parent, BinaryTreeNode<int> *root, int start)
{
  queue<BinaryTreeNode<int> *> q;
  BinaryTreeNode<int> *target = NULL;
  q.push(root);

  while (!q.empty())
  {
    BinaryTreeNode<int> *front = q.front();
    q.pop();

    if (front->data == start)
    {
      target = front;
    }

    if (front->left)
    {
      parent[front->left] = front;
      q.push(front->left);
    }
    if (front->right)
    {
      parent[front->right] = front;
      q.push(front->right);
    }
  }

  return target;
}

int timeToBurnTree(BinaryTreeNode<int> *root, int start)
{
  map<BinaryTreeNode<int> *, BinaryTreeNode<int> *> parent;
  BinaryTreeNode<int> *target = markParents(parent, root, start);

  queue<BinaryTreeNode<int> *> q;
  map<BinaryTreeNode<int> *, bool> vis;
  q.push(target);
  vis[target] = true;
  int time = 0;

  while (!q.empty())
  {
    int size = q.size();
    int cnt = 0;
    for (int i = 0; i < size; i++)
    {
      auto front = q.front();
      q.pop();

      if (front->left && !vis[front->left])
      {
        q.push(front->left);
        vis[front->left] = true;
        cnt++;
      }
      if (front->right && !vis[front->right])
      {
        q.push(front->right);
        vis[front->right] = true;
        cnt++;
      }
      if (parent[front] && !vis[parent[front]])
      {
        q.push(parent[front]);
        vis[parent[front]] = true;
        cnt++;
      }
    }
    if (cnt > 0)
      time++;
  }

  return time;
}