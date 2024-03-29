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
  // https://leetcode.com/problems/merge-in-between-linked-lists/
  ListNode *mergeInBetween(ListNode *list1, int a, int b, ListNode *list2)
  {
    ListNode *ath = list1, *bth = list1, *list2End = list2;

    while (list2End->next)
    {
      list2End = list2End->next;
    }

    while (a > 1 || b > 0)
    {
      if (a > 1)
      {
        ath = ath->next;
        a--;
      }
      if (b > 0)
      {
        bth = bth->next;
        b--;
      }
    }

    ath->next = list2;
    list2End->next = bth->next;

    return list1;
  }
};