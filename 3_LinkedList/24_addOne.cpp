class Solution
{
public:
  int carry = 0;
  void add(Node *head)
  {
    if (!head->next)
    {
      head->data = head->data + 1;
      carry = head->data / 10;
      head->data = head->data % 10;
      return;
    }

    add(head->next);
    if (carry)
    {
      head->data = head->data + 1;
      carry = head->data / 10;
      head->data = head->data % 10;
    }
  }

  Node *addOne(Node *head)
  {
    // Your Code here
    // return head of list after adding one
    add(head);
    if (carry == 1)
    {
      Node *temp = new Node(carry);
      temp->next = head;
      head = temp;
    }
    return head;
  }
};