class Node
{
public:
  int cnt;
  int key;
  int value;
  Node *next;
  Node *prev;

  Node(int key, int value)
  {
    this->key = key;
    this->value = value;
    next = prev = NULL;
    cnt = 1;
  }
};

class List
{
public:
  Node *head;
  Node *tail;
  int size;

  List()
  {
    head = new Node(0, 0);
    tail = new Node(0, 0);
    head->next = tail;
    tail->prev = head;
    size = 0;
  }

  void addNode(Node *newNode)
  {
    Node *temp = head->next;
    head->next = newNode;
    newNode->next = temp;
    newNode->prev = head;
    temp->prev = newNode;
    size++;
  }

  void deleteNode(Node *newNode)
  {
    newNode->next->prev = newNode->prev;
    newNode->prev->next = newNode->next;
    size--;
  }
};

class LFUCache
{
public:
  map<int, Node *> keyNode;
  map<int, List *> freq;
  int currSize;
  int minFreq;
  int maxSize;
  LFUCache(int capacity)
  {
    this->currSize = 0;
    this->maxSize = capacity;
    this->minFreq = 0;
  }

  void updateFreqList(Node *node)
  {
    keyNode.erase(node->key);
    freq[node->cnt]->deleteNode(node);

    if (minFreq == node->cnt && freq[node->cnt]->size == 0)
    {
      minFreq++;
    }

    List *higherFreq = new List();
    if (freq.find(node->cnt + 1) != freq.end())
    {
      higherFreq = freq[node->cnt + 1];
    }
    node->cnt += 1;
    higherFreq->addNode(node);
    freq[node->cnt] = higherFreq;
    keyNode[node->key] = node;
  }

  int get(int key)
  {
    if (keyNode.find(key) != keyNode.end())
    {
      Node *res = keyNode[key];
      int ans = res->value;
      updateFreqList(res);
      return ans;
    }
    return -1;
  }

  void put(int key, int value)
  {
    if (maxSize == 0)
      return;

    if (keyNode.find(key) != keyNode.end())
    {
      Node *res = keyNode[key];
      res->value = value;
      updateFreqList(res);
    }
    else
    {
      if (maxSize == currSize)
      {
        List *newList = freq[minFreq];
        keyNode.erase(newList->tail->prev->key);
        newList->deleteNode(newList->tail->prev);
        currSize--;
      }
      currSize++;
      minFreq = 1;
      Node *newNode = new Node(key, value);
      List *ll = new List();
      if (freq.find(minFreq) != freq.end())
      {
        ll = freq[minFreq];
      }
      ll->addNode(newNode);
      keyNode[key] = newNode;
      freq[minFreq] = ll;
    }
  }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */