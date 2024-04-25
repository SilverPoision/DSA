/*
Given a binary tree, the task is to check for every node,
its value is equal to the sum of values of its immediate
left and right child. For NULL values, consider the value
to be 0.
https://takeuforward.org/data-structure/check-for-children-sum-property-in-a-binary-tree/
*/

void changeTree(BinaryTreeNode<int> *root)
{
  if (!root)
    return;

  // Sum of left and right child and update the parent if needed
  int count = 0;
  if (root->left)
    count += root->left->data;
  if (root->right)
    count += root->right->data;

  if (count >= root->data)
    root->data = count;
  else
  {
    // Update childs because we can not decrese the parent or any child
    if (root->left)
      root->left->data = root->data;
    else if (root->right)
      root->right->data = root->data;
  }

  changeTree(root->left);
  changeTree(root->right);

  // Update root
  int tot = 0;
  if (root->left)
    tot += root->left->data;
  if (root->right)
    tot += root->right->data;
  if (root->left || root->right)
    root->data = tot;
}

// check
bool check(Node *r)
{
  if (!r || (!r->left && !r->right))
    return true; // root,leaf
  int ld = r->left ? r->left->data : 0;
  int rd = r->right ? r->right->data : 0;
  return (r->data == ld + rd) && check(r->left) && check(r->right);
}
bool isParentSum(Node *r) { return check(r); }