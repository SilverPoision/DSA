class Solution
{
public:
  void deleteNode(Node *head)
  {
    if (head->prev)
      head->prev->next = head->next;
    if (head->next)
      head->next->prev = head->prev;
  }
  void deleteAllOccurOfX(struct Node **head_ref, int x)
  {
    // Write your code here
    if (!(*head_ref))
      return;

    Node *ptr = *head_ref;
    if ((*head_ref)->data == x)
    {
      *head_ref = ptr->next;
      ptr = *head_ref;
    }

    while (ptr)
    {
      if (ptr->data == x)
      {
        deleteNode(ptr);
      }
      ptr = ptr->next;
    }
  }
};