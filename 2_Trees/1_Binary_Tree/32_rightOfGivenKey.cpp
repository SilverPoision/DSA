class Solution
{
public:
  Node *nextRight(Node *root, int key)
  {
    // code here
    if (root == NULL)
      return NULL;
    queue<Node *> q;
    q.push(root);
    Node *ans;

    while (!q.empty())
    {
      int k = q.size();
      while (k)
      {
        k--;
        auto front = q.front();
        q.pop();

        if (front->data == key)
        {
          if (k > 0)
          {
            ans = q.front();
          }
          else
          {
            ans = new Node(-1);
          }
          break;
        }

        if (front->left)
          q.push(front->left);
        if (front->right)
          q.push(front->right);
      }
    }

    return ans;
  }
};