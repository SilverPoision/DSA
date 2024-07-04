class Solution
{
public:
  // https://www.geeksforgeeks.org/problems/remove-all-occurences-of-duplicates-in-a-linked-list/1
  Node *removeAllDuplicates(struct Node *head)
  {
    // code here
    // Node *n = head;
    Node *prev = new Node(-1);
    Node *temp = prev;
    while (head)
    {
      Node *t = head->next;

      while (t && head->data == t->data)
      {
        t = t->next;
      }

      if (t == head->next)
      {
        prev->next = head;
        prev = prev->next;
      }
      head = t;
    }

    prev->next = NULL;

    return temp->next;
  }
};