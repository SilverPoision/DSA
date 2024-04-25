/****************************************************************

    Following is the class structure of the Node class:

        class Node
        {
        public:
            int data;
            Node *next;
            Node()
            {
                this->data = 0;
                next = NULL;
            }
            Node(int data)
            {
                this->data = data;
                this->next = NULL;
            }
            Node(int data, Node* next)
            {
                this->data = data;
                this->next = next;
            }
        };


*****************************************************************/

class Stack
{
  // Write your code here
  int size;
  Node *head = NULL;

public:
  Stack()
  {
    // Write your code here
  }

  int getSize()
  {
    // Write your code here
    return size;
  }

  bool isEmpty()
  {
    // Write your code here
    return size == 0;
  }

  void push(int data)
  {
    // Write your code here
    if (head == NULL)
    {
      head = new Node(data);
      size++;
      return;
    }
    Node *newNode = new Node(data, head);
    head = newNode;
    size++;
  }

  void pop()
  {
    // Write your code here
    if (size == 0)
      return;
    head = head->next;
    size--;
  }

  int getTop()
  {
    // Write your code here
    if (size == 0)
      return -1;
    return head->data;
  }
};