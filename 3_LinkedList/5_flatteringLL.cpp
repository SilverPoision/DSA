Node *merge(Node *l1, Node *l2)
{
  if (!l1)
    return l2;
  if (!l2)
    return l1;

  Node *res = new Node(0);
  Node *ptr = res;

  while (l1 && l2)
  {
    if (l1->data < l2->data)
    {
      res->bottom = l1;
      l1 = l1->bottom;
    }
    else
    {
      res->bottom = l2;
      l2 = l2->bottom;
    }
    res = res->bottom;
  }

  if (l1)
    res->bottom = l1;
  if (l2)
    res->bottom = l2;

  return ptr->bottom;
}

Node *flatten(Node *root)
{
  // Your code here
  if (!root)
    return root;
  Node *res = root;

  while (root)
  {
    res = merge(res, root->next);
    root = root->next;
  }

  return res;
}