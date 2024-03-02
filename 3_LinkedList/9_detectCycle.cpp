class Solution
{
public:
  bool hasCycle(ListNode *head)
  {
    if (!head)
      return false;
    map<ListNode *, bool> m;

    while (head)
    {
      if (m[head] == true)
        return true;
      m[head] = true;
      head = head->next;
    }
    return false;
  }
};

// Optimal
class Solution
{
public:
  bool hasCycle(ListNode *head)
  {
    if (!head)
      return false;
    ListNode *fast = head, *slow = head;

    while (slow && fast && fast->next)
    {
      fast = fast->next->next;
      slow = slow->next;
      if (fast == slow)
        return true;
    }

    return false;
  }
};