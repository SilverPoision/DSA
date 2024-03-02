// C++ program to find LIS on LinkedList
#include <bits/stdc++.h>
using namespace std;

// Structure of a node
class Node
{
public:
  int data;
  struct Node *next;

  // "count" variable is to keep track
  // of LIS_LENGTH ending with
  // that particular element
  int count;
};

// Function to find the length of the LIS
int LIS(struct Node *head)
{
  // If linked list is empty length is 0
  if (head == NULL)
    return 0;

  // If linked list has only one node
  // LIS length is 1
  if (head->next == NULL)
    return 1;

  Node *curr, *prev;
  Node *ref = head;
  int size = 0;
  int maxS = 0;

  while (ref != NULL)
  {
    curr = ref->next;
    prev = ref;
    size = 1;
    while (curr != NULL)
    {
      if (curr->data > prev->data)
      {
        size++;
        prev = curr;
      }

      curr = curr->next;
    }
    maxS = max(maxS, size);
    ref = ref->next;
  }

  return maxS;
}

// Function to push a node in linked list
void push(struct Node **head_ref,
          int new_data)
{
  // Allocate node
  Node *new_node = new Node();

  // Put in the data
  new_node->data = new_data;

  // Link the old list with the new node
  new_node->next = (*head_ref);

  // Assign count value to 1
  new_node->count = 1;

  // Move the head to point the new node
  (*head_ref) = new_node;
}

// Driver code
int main()
{
  // Start with the empty list
  struct Node *head = NULL;

  // Create a linked list
  // Created linked list will be
  // 3->10->2->1->20
  push(&head, 80);
  push(&head, 40);
  push(&head, 7);
  push(&head, 10);
  push(&head, 3);
  push(&head, 50);

  // Call LIS function which calculates
  // LIS of Linked List
  int ans = LIS(head);
  cout << ans;
  return 0;
}
