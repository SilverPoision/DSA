#include <bits/stdc++.h>
// https://www.codingninjas.com/studio/problems/add-first-and-second-reversed-half_759344
Node *reverseList(Node *h)
{
  Node *prev = nullptr, *next, *head = h;
  while (head)
  {
    next = head->next;
    head->next = prev;
    prev = head;
    head = next;
  }

  return prev;
}

Node *findMiddle(Node *head)
{
  Node *slow = head, *fast = head;
  while (fast && fast->next && fast->next->next)
  {
    fast = fast->next->next;
    slow = slow->next;
  }
  Node *t = slow->next;
  slow->next = nullptr;

  return t;
}

Node *addFirstAndReversedSecondHalf(Node *head)
{
  if (!head || !head->next)
    return head;

  Node *first = head;
  Node *second = findMiddle(head);
  first = reverseList(first);

  int carry = 0;
  Node *dummy = new Node(0);
  Node *temp = dummy;

  while (second || first || carry)
  {
    int num = 0;

    if (first)
    {
      num += first->data;
      first = first->next;
    }
    if (second)
    {
      num += second->data;
      second = second->next;
    }

    if (carry)
      num += carry;

    carry = num / 10;
    temp->next = new Node(num % 10);
    temp = temp->next;
  }

  Node *h = reverseList(dummy->next);

  while (h && h->data == 0)
    h = h->next;

  return h ? h : new Node(0);
}
