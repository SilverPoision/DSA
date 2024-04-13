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
  ListNode *removeZeroSumSublists(ListNode *head)
  {
    ListNode *first = new ListNode();
    first->next = head;
    unordered_map<int, ListNode *> hash;
    hash[0] = first;

    int sum = 0;

    while (head)
    {
      sum += head->val;
      if (hash.find(sum) != hash.end())
      {
        ListNode *temp = hash[sum]->next;
        int tSum = sum;
        while (temp != head)
        {
          tSum += temp->val;
          hash.erase(tSum);
          temp = temp->next;
        }
        hash[sum]->next = head->next;
      }
      else
      {
        hash[sum] = head;
      }
      head = head->next;
    }

    return first->next;
  }
};