class Solution
{
public:
  // https://leetcode.com/problems/merge-nodes-in-between-zeros/?envType=daily-question&envId=2024-07-04
  ListNode *mergeNodes(ListNode *head)
  {
    int sum = 0;
    ListNode *prev = head;
    ListNode *t = prev;

    while (head)
    {
      if (head->val == 0 && prev != head)
      {
        prev->val = sum;
        sum = 0;
        if (head->next)
        {
          prev->next = head;
          prev = prev->next;
        }
        else
          prev->next = NULL;
      }
      sum += head->val;
      head = head->next;
    }

    return t;
  }
};