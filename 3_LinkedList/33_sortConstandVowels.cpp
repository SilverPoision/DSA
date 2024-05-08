class Solution
{
public:
  // https://www.geeksforgeeks.org/problems/arrange-consonants-and-vowels/1
  struct Node *arrangeCV(Node *head)
  {
    // Code here
    vector<char> vowels = {'a', 'e', 'i', 'o', 'u'};
    Node *cons = new Node('0'), *vow = new Node('0');
    Node *consPtr = cons, *vowPtr = vow;

    while (head)
    {
      bool f = false;
      for (auto it : vowels)
      {
        if (it == head->data)
        {
          f = true;
          break;
        }
      }
      if (f)
      {
        vow->next = head;
        vow = vow->next;
      }
      else
      {
        cons->next = head;
        cons = cons->next;
      }
      head = head->next;
    }

    vow->next = consPtr->next;
    cons->next = NULL;

    return vowPtr->next;
  }
};