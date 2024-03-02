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
  Node *removeDuplicates(struct Node *head)
  {
    Node *ptr = head;
    while (head && head->next)
    {
      if (head->next->data == head->data)
      {
        deleteNode(head->next);
      }
      else
      {
        head = head->next;
      }
    }

    return ptr;
  }
};