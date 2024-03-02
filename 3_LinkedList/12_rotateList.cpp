// Brute
class Solution
{
public:
  ListNode *findEnd(ListNode *head)
  {
    while (head && head->next)
    {
      if (head->next->next == NULL)
      {
        break;
      }
      head = head->next;
    }
    return head;
  }
  ListNode *rotateRight(ListNode *head, int k)
  {
    if (!head || !head->next)
      return head;
    ListNode *start = head, *end = findEnd(head);

    while (k)
    {
      end->next->next = start;
      start = end->next;
      end->next = NULL;
      end = findEnd(start);
      k--;
    }
    return start;
  }
};

// Optimal
class Solution
{
public:
  ListNode *rotateRight(ListNode *head, int k)
  {
    if (!head || !head->next || k == 0)
      return head;

    ListNode *curr = head;
    int len = 1;
    while (curr->next)
    {
      curr = curr->next;
      len++;
    }

    curr->next = head;
    k = k % len;
    k = len - k;
    while (k--)
      curr = curr->next;

    head = curr->next;
    curr->next = NULL;

    return head;
  }
};