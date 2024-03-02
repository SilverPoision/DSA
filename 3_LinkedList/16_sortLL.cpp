class Solution
{
public:
  ListNode *sortList(ListNode *head)
  {
    if (!head || !head->next)
      return head;

    ListNode *slow = head, *fast = head, *temp = NULL;

    while (fast && fast->next)
    {
      temp = slow;
      slow = slow->next;
      fast = fast->next->next;
    }

    temp->next = NULL;

    ListNode *l1 = sortList(head);
    ListNode *l2 = sortList(slow);
    return merge(l1, l2);
  }

  ListNode *merge(ListNode *l1, ListNode *l2)
  {
    if (!l1)
      return l2;
    if (!l2)
      return l1;

    ListNode *ptr = new ListNode();
    ListNode *curr = ptr;

    while (l1 && l2)
    {
      if (l1->val <= l2->val)
      {
        curr->next = l1;
        l1 = l1->next;
      }
      else
      {
        curr->next = l2;
        l2 = l2->next;
      }
      curr = curr->next;
    }

    if (l1)
    {
      curr->next = l1;
      l1 = l1->next;
    }

    if (l2)
    {
      curr->next = l2;
      l2 = l2->next;
    }

    return ptr->next;
  }
};