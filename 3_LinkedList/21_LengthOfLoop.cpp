int countNodesinLoop(struct Node *head)
{
  // Code here
  Node *fast = head, *slow = head, *dummy = head;

  while (fast && fast->next)
  {
    fast = fast->next->next;
    slow = slow->next;

    if (fast == slow)
    {
      while (slow != dummy)
      {
        slow = slow->next;
        dummy = dummy->next;
      }

      dummy = dummy->next;

      int cnt = 1;

      while (dummy != slow)
      {
        cnt++;
        dummy = dummy->next;
      }

      return cnt;
    }
  }

  return 0;
}