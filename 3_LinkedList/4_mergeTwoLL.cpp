class Solution
{
public:
  ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
  {
    if (list1 == NULL)
      return list2;
    if (list2 == NULL)
      return list1;

    ListNode *ptr = list1;

    if (list1->val < list2->val)
    {
      list1 = list1->next;
    }
    else
    {
      ptr = list2;
      list2 = list2->next;
    }

    ListNode *list = ptr;

    while (list1 && list2)
    {
      if (list1->val > list2->val)
      {
        list->next = list2;
        list2 = list2->next;
      }
      else
      {
        list->next = list1;
        list1 = list1->next;
      }
      list = list->next;
    }

    if (!list1)
      list->next = list2;
    else
      list->next = list1;

    return ptr;
  }
};

// InPlace
class Solution
{
public:
  ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
  {
    if (!l1)
      return l2;
    if (!l2)
      return l1;

    if (l1->val > l2->val)
      std::swap(l1, l2);
    ListNode *res = l1;

    while (l1 && l2)
    {
      ListNode *temp = NULL;
      while (l1 && l1->val <= l2->val)
      {
        temp = l1;
        l1 = l1->next;
      }
      temp->next = l2;
      std::swap(l1, l2);
    }

    return res;
  }
};