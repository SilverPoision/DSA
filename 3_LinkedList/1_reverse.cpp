class Solution
{
public:
  ListNode *reverseList(ListNode *head)
  {
    ListNode *prev = NULL, *next = NULL;
    while (head)
    {
      next = head->next;
      head->next = prev;
      prev = head;
      head = next;
    }
    return prev;
  }
};

class Solution
{
public:
  ListNode *h;
  void reverse(ListNode *head)
  {
    if (!head->next)
    {
      h = head;
      return;
    }
    reverse(head->next);
    head->next->next = head;
    head->next = NULL;
  }
  ListNode *reverseList(ListNode *head)
  {
    if (!head)
      return NULL;
    reverse(head);
    return h;
  }
};