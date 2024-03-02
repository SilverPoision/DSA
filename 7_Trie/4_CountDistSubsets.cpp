struct Node
{
  Node *child[26];

  void put(char ch, Node *node)
  {
    child[ch - 'a'] = node;
  }

  Node *get(char ch)
  {
    return child[ch - 'a'];
  }

  bool containsKey(char ch)
  {
    return child[ch - 'a'];
  }
};

class Trie
{
  Node *root;

public:
  int cnt = 0;
  Trie()
  {
    root = new Node;
  }

  void insert(string word)
  {
    Node *node = root;
    for (int i = 0; i < word.size(); i++)
    {
      if (!node->containsKey(word[i]))
      {
        node->put(word[i], new Node());
        cnt++;
      }
      node = node->get(word[i]);
    }
  }
};

int countDistinctSubstrings(string &s)
{
  //    Write your code here.
  Trie t;
  for (int i = 0; i < s.size(); i++)
  {
    t.insert(s.substr(i));
  }

  return t.cnt + 1;
}
