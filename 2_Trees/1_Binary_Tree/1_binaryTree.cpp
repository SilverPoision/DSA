#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
  int data;
  Node *left;
  Node *right;

  Node(int item)
  {
    data = item;
    left = right = NULL;
  }
};

void InOrder(Node *node)
{
  if (node == NULL)
  {
    return;
  }
  InOrder(node->left);
  cout << node->data << endl;
  InOrder(node->right);
}

void postOrder(Node *node)
{
  if (node == NULL)
  {
    return;
  }
  postOrder(node->left);
  postOrder(node->right);
  cout << node->data << endl;
}

void preOrder(Node *node)
{
  if (node == NULL)
  {
    return;
  }
  cout << node->data << " ";

  preOrder(node->left);
  preOrder(node->right);
}

void iterativePre(Node *node)
{
  stack<Node *> st;
  st.push(node);

  while (!st.empty())
  {
    Node *top = st.top();
    st.pop();
    cout << top->data << " ";

    if (top->right)
    {
      st.push(top->right);
    }
    if (top->left)
    {
      st.push(top->left);
    }
  }
}

void iterativePost(Node *node)
{
  stack<Node *> st;
  stack<Node *> res;

  st.push(node);

  while (!st.empty())
  {
    Node *top = st.top();
    st.pop();
    res.push(top);

    if (top->left)
    {
      st.push(top->left);
    }
    if (top->right)
    {
      st.push(top->right);
    }
  }

  while (!res.empty())
  {
    cout << res.top()->data << " ";
    res.pop();
  }
}

vector<int> postorderTraversal(TreeNode *root)
{
  // Single stack
  if (!root)
    return {};
  stack<TreeNode *> st;
  vector<int> ans;

  auto curr = root;

  while (curr != NULL || !st.empty())
  {
    if (curr)
    {
      st.push(curr);
      curr = curr->left;
    }
    else
    {
      auto temp = st.top()->right;

      if (!temp)
      {
        temp = st.top();
        st.pop();
        ans.push_back(temp->val);

        while (!st.empty() && temp == st.top()->right)
        {
          temp = st.top();
          st.pop();
          ans.push_back(temp->val);
        }
      }
      else
      {
        curr = temp;
      }
    }
  }

  return ans;
}

void iterativeInOrder(Node *node)
{
  stack<Node *> st;
  Node *n1 = node;

  while (n1 != NULL || !st.empty())
  {
    while (n1)
    {
      st.push(n1);
      n1 = n1->left;
    }

    n1 = st.top();
    st.pop();
    cout << n1->data << " ";
    n1 = n1->right;
  }
}

void bfs(Node *node)
{
  // levelOrderTraversal
  queue<Node *> q;
  q.push(node);

  while (!q.empty())
  {
    Node *front = q.front();
    q.pop();
    cout << front->data << " ";
    if (front->left)
    {
      q.push(front->left);
    }
    if (front->right)
    {
      q.push(front->right);
    }
  }
}

void print(vector<int> &ito, string s)
{
  cout << s << ": [";
  for (auto it : ito)
  {
    cout << it << ",";
  }
  cout << "]" << endl;
}

void prePostIn(Node *root)
{
  vector<int> pre, in, post;
  stack<pair<Node *, int>> st;
  st.push({root, 1});

  while (!st.empty())
  {
    auto top = st.top();
    st.pop();
    if (top.second == 1)
    {
      pre.push_back(top.first->data);
      top.second++;
      st.push(top);
      if (top.first->left)
      {
        st.push({top.first->left, 1});
      }
    }
    else if (top.second == 2)
    {
      in.push_back(top.first->data);
      top.second++;
      st.push(top);
      if (top.first->right)
      {
        st.push({top.first->right, 1});
      }
    }
    else if (top.second == 3)
    {
      post.push_back(top.first->data);
    }
  }

  print(pre, "PreOrder");
  print(in, "InOrder");
  print(post, "PostOrder");
}

int main()
{
  Node *root = new Node(1);
  root->left = new Node(2);
  root->right = new Node(3);
  root->left->left = new Node(4);
  root->left->right = new Node(5);
  root->right->right = new Node(7);
  root->right->left = new Node(6);
  prePostIn(root);
  return 0;
}

// creation
Node *solver(int i, vector<int> &arr)
{
  int n = arr.size();

  Node *head = new Node(arr[i]);

  if (i >= n)
    return NULL;

  head->left = solver(2 * i + 1, arr);
  head->right = solver(2 * i + 2, arr);

  return head;
}

Node *createTree(vector<int> &arr)
{
  // Write your code here.
  return solver(0, arr);
}