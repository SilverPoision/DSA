class Solution
{
public:
  ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
  {
    int l1 = 0, l2 = 0;

    ListNode *head1 = headA, *head2 = headB;

    while (head1 || head2)
    {
      if (head1)
      {
        head1 = head1->next;
        l1++;
      }
      if (head2)
      {
        head2 = head2->next;
        l2++;
      }
    }

    int diff = abs(l1 - l2);

    if (l1 > l2)
      std::swap(headA, headB);

    while (diff != 0 && headA)
    {
      headB = headB->next;
      diff--;
    }

    while (headA && headB)
    {
      if (headA == headB)
      {
        break;
      }
      else
      {
        headA = headA->next;
        headB = headB->next;
      }
    }
    if (!headA || !headB)
      return 0;
    return headA;
  }
};

// Optimal
class Solution
{
public:
  ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
  {
    if (!headA || !headB)
      return NULL;
    ListNode *head1 = headA, *head2 = headB;

    while (head1 != head2)
    {
      head1 = head1 == NULL ? headB : head1->next;
      head2 = head2 == NULL ? headA : head2->next;
    }

    return head1;
  }
};