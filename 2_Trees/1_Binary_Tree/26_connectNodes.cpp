class Solution
{
public:
  Node *connect(Node *root)
  {
    if (!root)
      return NULL;
    queue<Node *> q;
    q.push(root);

    while (!q.empty())
    {
      int k = q.size();
      while (k != 0)
      {
        k--;
        Node *front = q.front();
        q.pop();
        front->next = k != 0 ? q.front() : NULL;
        if (front->left)
          q.push(front->left);
        if (front->right)
          q.push(front->right);
      }
    }
    return root;
  }
};

// Optimal
class Solution
{
public:
  Node *connect(Node *root)
  {
    if (!root)
      return NULL;
    Node *next = root->left, *curr = root;

    while (next && curr)
    {
      curr->left->next = curr->right;
      if (curr->next)
      {
        curr->right->next = curr->next->left;
      }
      curr = curr->next;
      if (!curr)
      {
        curr = next;
        next = next->left;
      }
    }

    return root;
  }
};