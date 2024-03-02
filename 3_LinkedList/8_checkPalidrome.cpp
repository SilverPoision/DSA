class Solution
{
public:
  ListNode *reverse(ListNode *head)
  {
    ListNode *prev = NULL, *temp = NULL;
    while (head)
    {
      temp = head->next;
      head->next = prev;
      prev = head;
      head = temp;
    }
    return prev;
  }
  bool isPalindrome(ListNode *head)
  {
    if (!head || !head->next)
      return true;
    ListNode *head1 = head;

    ListNode *fast = head, *slow = head;
    while (fast->next && fast->next->next)
    {
      slow = slow->next;
      fast = fast->next->next;
    }

    slow->next = reverse(slow->next);
    slow = slow->next;

    while (slow && head)
    {
      if (slow->val != head->val)
        return false;
      else
      {
        slow = slow->next;
        head = head->next;
      }
    }

    return true;
  }
};