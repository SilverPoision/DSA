class Solution
{
public:
  // https://leetcode.com/problems/double-a-number-represented-as-a-linked-list/?envType=daily-question&envId=2024-05-07
  ListNode *rev(ListNode *head)
  {
    ListNode *temp, *prev = NULL;

    while (head)
    {
      temp = head->next;
      head->next = prev;
      prev = head;
      head = temp;
    }

    return prev;
  }
  ListNode *doubleIt(ListNode *head)
  {
    head = rev(head);

    ListNode *ptr = head;
    int carry = 0;

    while (ptr)
    {
      ptr->val = (ptr->val * 2) + carry;
      carry = ptr->val / 10;
      ptr->val = ptr->val % 10;
      ptr = ptr->next;
    }

    if (carry)
    {
      return new ListNode(carry, rev(head));
    }

    return rev(head);
  }
};