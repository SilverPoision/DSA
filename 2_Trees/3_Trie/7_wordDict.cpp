class TrieNode
{
public:
  TrieNode *child[26];
  bool isTerminal;

  TrieNode(char data)
  {
    for (int i = 0; i < 26; i++)
    {
      child[i] = nullptr;
    }
    isTerminal = 0;
  }
};

class Trie
{
public:
  TrieNode *root;

  Trie()
  {
    root = new TrieNode('\0');
  }

  void insertUtil(TrieNode *root, string word)
  {
    if (word.size() == 0)
    {
      root->isTerminal = true;
      return;
    }
    int idx = word[0] - 'a';
    TrieNode *child;

    if (root->child[idx])
    {
      child = root->child[idx];
    }
    else
    {
      child = new TrieNode(word[0]);
      root->child[idx] = child;
    }

    insertUtil(child, word.substr(1));
  }

  void insert(string word)
  {
    insertUtil(root, word);
  }

  bool searchUtil(TrieNode *root, string word)
  {
    if (word.size() == 0)
    {
      return root->isTerminal;
    }

    int idx = word[0] - 'a';

    if (word[0] == '.')
    {
      for (int i = 0; i < 26; i++)
      {
        if (root->child[i])
        {
          if (searchUtil(root->child[i], word.substr(1)))
            return true;
        }
      }
    }
    else
    {
      if (!root->child[idx])
        return false;
      return searchUtil(root->child[idx], word.substr(1));
    }

    return false;
  }

  bool search(string word)
  {
    return searchUtil(root, word);
  }
};

class WordDictionary
{
public:
  Trie *root;
  WordDictionary() { root = new Trie(); }

  void addWord(string word)
  {
    root->insert(word);
  }

  bool search(string word) { return root->search(word); }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */