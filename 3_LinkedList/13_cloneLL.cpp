#include <bits/stdc++.h>
using namespace std;

/*
You are given a double Link List with one reference of each node
pointing to the next node just like in a single link list.
The second reference however can point to any node in the list
and not just the previous node.Write a program in O(n) time which
will create a copy of this list Asked in : Myntra, Expdia, Microsoft, J P Morgan

Solution:
1. Make a hashMap and put all the new nodes in the map and then
    again set the curr to start
2. Then set map[curr]->next = map[curr->next]
3. Then set map[curr]->random = map[curr->random]
*/

// This function clones a given linked list
Node *clone(Node *start)
{
  Node *curr = start, *copy;
  map<Node *, Node *> m;

  while (curr)
  {
    copy = new Node(curr->data);
    m[curr] = copy;
    curr = curr->next;
  }

  curr = start;

  while (curr)
  {
    m[curr]->next = m[curr->next];
    m[curr]->random = m[curr->random];
    curr = curr->next;
  }

  return m[start];
}

// Optimal
class Solution
{
public:
  Node *copyRandomList(Node *head)
  {
    Node *curr = head;

    // creating adjacent dummy node
    while (curr)
    {
      Node *temp = curr->next;
      curr->next = new Node(curr->val);
      curr->next->next = temp;
      curr = curr->next->next;
    }

    // assigning random pointers
    curr = head;
    while (curr)
    {
      if (curr->random)
      {
        curr->next->random = curr->random->next;
      }
      curr = curr->next->next;
    }

    // segregating the links;
    curr = head;
    Node *psudoHead = new Node(-1);
    Node *copy = psudoHead, *front;

    while (curr)
    {
      front = curr->next->next;
      copy->next = curr->next;
      curr->next = front;
      copy = copy->next;
      curr = front;
    }
    return psudoHead->next;
  }
};