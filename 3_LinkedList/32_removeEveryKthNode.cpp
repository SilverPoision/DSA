class Solution
{
public:
  // https://www.geeksforgeeks.org/problems/remove-every-kth-node/1
  Node *deleteK(Node *head, int k)
  {
    if (k == 1)
      return NULL;
    // Your code here
    Node *temp = head;

    while (temp)
    {
      int t = k - 2;
      while (t-- && temp)
      {
        temp = temp->next;
      }
      if (temp && temp->next)
        temp->next = temp->next->next;
      if (temp)
        temp = temp->next;
    }

    return head;
  }
};