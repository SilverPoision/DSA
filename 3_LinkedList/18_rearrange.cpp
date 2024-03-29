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
  void reorderList(ListNode *head)
  {
    ListNode *slow = head, *fast = head;

    while (fast->next && fast->next->next)
    {
      fast = fast->next->next;
      slow = slow->next;
    }

    ListNode *nNode = slow->next;
    slow->next = nullptr;

    ListNode *prev = nullptr;

    while (nNode)
    {
      ListNode *temp = nNode->next;
      nNode->next = prev;
      prev = nNode;
      nNode = temp;
    }

    nNode = prev;

    ListNode *ptr = head;

    while (nNode && ptr)
    {
      ListNode *temp = ptr->next;
      ptr->next = nNode;
      nNode = nNode->next;
      ptr->next->next = temp;
      ptr = temp;
    }
  }
};

/////

class Solution
{
public:
  ListNode *findMiddle(ListNode *head)
  {
    ListNode *fast = head, *slow = head, *prev;

    while (fast && fast->next)
    {
      prev = slow;
      fast = fast->next->next;
      slow = slow->next;
    }

    prev->next = NULL;
    return slow;
  }

  ListNode *reverse(ListNode *head)
  {
    ListNode *prev = NULL;
    while (head)
    {
      ListNode *temp = head->next;
      head->next = prev;
      prev = head;
      head = temp;
    }

    return prev;
  }

  ListNode *merge(ListNode *l1, ListNode *l2)
  {
    ListNode *res = new ListNode();
    ListNode *ptr = res;
    while (l1 || l2)
    {
      if (l1)
      {
        res->next = l1;
        res = res->next;
        l1 = l1->next;
      }
      if (l2)
      {
        res->next = l2;
        res = res->next;
        l2 = l2->next;
      }
    }

    return ptr->next;
  }

  void reorderList(ListNode *head)
  {
    if (!head || !head->next)
      return;
    ListNode *mid = findMiddle(head);
    ListNode *mid2 = reverse(mid);

    head = merge(head, mid2);
  }
};