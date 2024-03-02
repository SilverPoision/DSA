class Solution
{
public:
  ListNode *findTail(ListNode *head, int &cnt)
  {
    while (head->next)
    {
      head = head->next;
      cnt++;
    }
    return head;
  }

  ListNode *oddEvenList(ListNode *head)
  {
    if (!head || !head->next)
      return head;
    int cnt = 0;
    ListNode *curr = head->next;
    ListNode *tail = findTail(head, cnt);
    if (cnt == 1)
      return head;
    ListNode *prev = head;
    bool odd = false;

    while (cnt)
    {
      ListNode *temp = curr->next;
      if (!odd)
      {
        prev->next = curr->next;
        tail->next = curr;
        curr->next = NULL;
        tail = tail->next;
      }
      if (odd)
      {
        prev = curr;
      }
      curr = temp;
      odd = !odd;
      cnt--;
    }

    return head;
  }
};

class Solution
{
public:
  ListNode *oddEvenList(ListNode *head)
  {
    if (!head || !head->next || !head->next->next)
      return head;

    ListNode *evenNode = NULL, *evenTail = NULL, *oddNode = NULL, *oddTail = NULL;
    bool odd = false;

    while (head)
    {
      if (!odd)
      {
        if (oddNode == NULL)
        {
          oddNode = head;
          oddTail = head;
        }
        else
        {
          oddTail->next = head;
          oddTail = oddTail->next;
        }
      }
      else
      {
        if (evenNode == NULL)
        {
          evenNode = head;
          evenTail = head;
        }
        else
        {
          evenTail->next = head;
          evenTail = evenTail->next;
        }
      }
      odd = !odd;
      head = head->next;
    }

    evenTail->next = head;
    oddTail->next = head;

    oddTail->next = evenNode;
    return oddNode;
  }
};