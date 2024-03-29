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

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution
{
public:
  ListNode *h;
  bool solve(ListNode *head)
  {
    if (!head->next)
    {
      if (h->val != head->val)
        return false;
      else
        h = h->next;
      return true;
    }

    if (solve(head->next))
    {
      if (head->val == h->val)
      {
        h = h->next;
        return true;
      }
    }

    return false;
  }
  bool isPalindrome(ListNode *head)
  {
    h = head;
    return solve(head);
  }
};