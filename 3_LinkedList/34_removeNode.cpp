class Solution
{
public:
  // https://leetcode.com/problems/remove-nodes-from-linked-list/solutions/5118366/detailed-explanation-3-approaches-stack-recursion-reversal-o-1-space-efficient/?envType=daily-question&envId=2024-05-06
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
  ListNode *removeNodes(ListNode *head)
  {
    head = rev(head);

    int maxi = -1e9;

    ListNode *ptr = head, *prev = NULL;

    while (ptr)
    {
      if (ptr->val < maxi)
      {
        if (!prev)
          head = ptr;
        else
        {
          prev->next = ptr->next;
        }
      }
      else
      {
        prev = ptr;
        maxi = max(maxi, ptr->val);
      }
      ptr = ptr->next;
    }

    return rev(head);
  }
};

// Recursion
class Solution
{
public:
  ListNode *removeNodes(ListNode *head)
  {
    if (head == nullptr)
    {
      return nullptr;
    }
    ListNode *node = head;
    ListNode *nxtGreater = removeNodes(node->next);

    node->next = nxtGreater;
    if (nxtGreater == nullptr || node->val >= nxtGreater->val)
    {
      return node;
    }
    return nxtGreater;
  }
};