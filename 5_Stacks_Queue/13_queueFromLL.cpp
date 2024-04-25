/**
 * Definition of linked list
 * class Node {
 *
 * public:
 *     int data;
 *     Node* next;
 *     Node() : data(0), next(nullptr) {}
 *     Node(int x) : data(x), next(nullptr) {}
 *     Node(int x, Node* next) : data(x), next(next) {}
 * };
 *
 * Definition of Queue
 * struct Queue {
 *   Node* front;
 *   Node* rear;
 *   void push(int);
 *   int pop();
 *
 *   Queue() {
 *       front = rear = NULL;
 *   }
 * };
 */

void Queue::push(int x)
{
  // Write Your Code Here
  if (!rear)
  {
    front = new Node(x);
    rear = front;
    return;
  }

  Node *newNode = new Node(x);
  rear->next = newNode;
  rear = newNode;
}

int Queue::pop()
{
  // Write Your Code Here
  if (!front)
    return -1;
  int ele = front->data;
  front = front->next;
  if (front == NULL)
    rear = NULL;

  return ele;
}