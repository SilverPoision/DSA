class Solution
{
public:
  TNode *help(LNode *&head, int n)
  {
    if (n <= 0 || head == NULL)
      return NULL;

    TNode *left = help(head, n / 2);
    TNode *root = new TNode(head->data);
    root->left = left;
    head = head->next;

    root->right = help(head, (n - (n / 2)) - 1);

    return root;
  }
  int countNodes(LNode *head)
  {
    if (!head)
      return 0;

    return 1 + countNodes(head->next);
  }
  TNode *sortedListToBST(LNode *head)
  {
    // code here
    int n = countNodes(head);
    return help(head, n);
  }
};