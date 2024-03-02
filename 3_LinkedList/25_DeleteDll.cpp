class Solution
{
public:
  Node *deleteNode(Node *head_ref, int x)
  {
    // Your code here
    if (x == 1)
      return head_ref->next;
    Node *ptr = head_ref;
    int cnt = 1;

    while (ptr->next && cnt < x)
    {
      cnt++;
      ptr = ptr->next;
    }

    if (ptr->prev)
      ptr->prev->next = ptr->next;
    if (ptr->next)
      ptr->next->prev = ptr->prev;

    return head_ref;
  }
};