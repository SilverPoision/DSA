class Solution
{
public:
  int countNodes(struct Node *root)
  {
    if (!root)
      return 0;

    return 1 + (countNodes(root->left) + countNodes(root->right));
  }
  bool isCompleteTree(struct Node *tree, int index, int nodes)
  {
    if (!tree)
      return true;

    if (index >= nodes)
    {
      return false;
    }

    return (isCompleteTree(tree->left, 2 * index + 1, nodes) && isCompleteTree(tree->right, 2 * index + 2, nodes));
  }

  bool isHeapUtil(struct Node *tree)
  {
    // code here
    if (!tree->left && !tree->right)
      return true;

    if (tree->right == NULL)
    {
      return tree->data >= tree->left->data;
    }

    if (tree->data >= tree->left->data && tree->data >= tree->right->data)
    {
      return (isHeapUtil(tree->left) && isHeapUtil(tree->right));
    }

    return false;
  }

  bool isHeap(struct Node *tree)
  {
    int index = 0;
    int nodes = countNodes(tree);

    if (isCompleteTree(tree, index, nodes) && isHeapUtil(tree))
    {
      return true;
    }
    return false;
  }
};