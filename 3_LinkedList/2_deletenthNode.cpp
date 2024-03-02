/*
Given a Linked List and a number n, write a function that returns
the value at the n’th node from the end of the Linked List.

The solution just use an array and store all the keys in tothe arr
and take the lenghthof the array and just gets the last n th key as answer.

thi can also be solved by taking the length in consideration.
or by using 2 pointers approch.
*/

class Solution
{
public:
  ListNode *removeNthFromEnd(ListNode *head, int n)
  {
    ListNode *start = new ListNode();
    start->next = head;
    ListNode *fast = start;
    ListNode *slow = start;

    for (int i = 0; i < n; i++)
    {
      fast = fast->next;
    }

    while (fast->next != NULL)
    {
      fast = fast->next;
      slow = slow->next;
    }

    slow->next = slow->next->next;
    return start->next;
  }
};