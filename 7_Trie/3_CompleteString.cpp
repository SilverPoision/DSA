#include <bits/stdc++.h>

struct Node
{
  Node *child[26];
  bool isTerminal;

  bool containsKey(char ch)
  {
    return (child[ch - 'a'] != NULL);
  }

  Node *get(char ch)
  {
    return child[ch - 'a'];
  }

  void put(char ch, Node *node)
  {
    child[ch - 'a'] = node;
  }

  void setEnd()
  {
    isTerminal = true;
  }

  bool isEnd()
  {
    return isTerminal;
  }
};

class Trie
{
public:
  Node *root;

  Trie()
  {
    root = new Node();
  }

  void insert(string word)
  {
    Node *node = root;
    for (int i = 0; i < word.length(); i++)
    {
      if (!node->containsKey(word[i]))
      {
        node->put(word[i], new Node());
      }
      node = node->get(word[i]);
    }
    node->setEnd();
  }

  bool search(string word)
  {
    Node *node = root;
    for (int i = 0; i < word.length(); i++)
    {
      if (node->containsKey(word[i]))
      {
        node = node->get(word[i]);
      }
      else
      {
        return false;
      }
    }
    return node->isTerminal;
  }
};

string completeString(int n, vector<string> &a)
{
  // Write your code here.
  Trie t;
  for (auto it : a)
  {
    t.insert(it);
  }

  string longest = "";

  for (auto word : a)
  {
    bool flag = true;
    string st = "";
    for (int i = 0; i < word.size(); i++)
    {
      st += word[i];
      if (!t.search(st))
      {
        flag = false;
      }
    }
    if (flag)
    {
      if (longest.length() < word.length())
      {
        longest = word;
      }
      else if (longest.length() == word.length() && longest > word)
      {
        longest = word;
      }
    }
  }

  if (longest == "")
  {
    return "None";
  }
  return longest;
}
