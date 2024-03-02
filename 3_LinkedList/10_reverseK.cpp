// https://takeuforward.org/data-structure/reverse-linked-list-in-groups-of-size-k/

class Solution
{
public:
  int findLength(ListNode *head)
  {
    int len = 0;
    while (head)
    {
      len++;
      head = head->next;
    }

    return len;
  }
  ListNode *reverseKGroup(ListNode *head, int k)
  {
    if (!head || !head->next)
      return head;

    int len = findLength(head);
    ListNode *dummy = new ListNode(0);
    dummy->next = head;

    ListNode *curr, *nex, *pre = dummy;

    while (len >= k)
    {
      curr = pre->next;
      nex = curr->next;

      for (int i = 1; i < k; i++)
      {
        curr->next = nex->next;
        nex->next = pre->next;
        pre->next = nex;
        nex = curr->next;
      }
      pre = curr;
      len -= k;
    }

    return dummy->next;
  }
};

class Solution
{
public:
  ListNode *reverseKGroup(ListNode *head, int k)
  {
    ListNode *dummy = new ListNode(0);
    dummy->next = head;
    ListNode *groupPrev = dummy; // groupPrev->next should always point to start of the ll

    while (true)
    {
      ListNode *kth = findKth(groupPrev, k);
      if (!kth)
        break;
      ListNode *groupNext = kth->next;

      ListNode *prev = kth->next, *curr = groupPrev->next;

      while (curr != groupNext)
      {
        ListNode *tmp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = tmp;
      }

      /*
      before the first iteration, the groupPrev was the dummy node ,
      it's next value is 1 right, even after the first iteration
      the groupPrev.next is 1 and the kth is 2,  hence we need to
      do 2 things , 1. point groupPrev.next to 2  and then update
      the groupPrev to 1 (the last node), so for doing 1 we need
      to save the last node aka groupPrev.next value(1) and then
      point to 2.
      */

      ListNode *temp = groupPrev->next;
      groupPrev->next = kth;
      groupPrev = temp;
    }
    return dummy->next;
  }

  ListNode *findKth(ListNode *head, int k)
  {
    while (k > 0 && head != NULL)
    {
      head = head->next;
      k--;
    }
    return head;
  }
};