class TrieNode
{
public:
  char data;
  TrieNode *child[26];
  bool isTerminal;

  TrieNode(char data)
  {
    this->data = data;
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
    if (word.length() == 0)
    {
      root->isTerminal = true;
      return;
    }

    int index = word[0] - 'a';
    TrieNode *child;

    // present
    if (root->child[index] != NULL)
    {
      child = root->child[index];
    }
    else
    {
      // absent
      child = new TrieNode(word[0]);
      root->child[index] = child;
    }

    insertUtil(child, word.substr(1));
  }

  void insert(string word)
  {
    insertUtil(root, word);
  }

  void printUtil(TrieNode *curr, string prefix, vector<string> &temp)
  {
    if (curr->isTerminal)
    {
      temp.push_back(prefix);
    }

    for (char ch = 'a'; ch <= 'z'; ch++)
    {
      TrieNode *next = curr->child[ch - 'a'];
      if (next != NULL)
      {
        prefix.push_back(ch);
        printUtil(next, prefix, temp);
        prefix.pop_back();
      }
    }
  }

  vector<vector<string>> getSuggestions(string str)
  {
    TrieNode *prev = root;
    vector<vector<string>> output;
    string prefix = "";

    for (int i = 0; i < str.length(); i++)
    {
      char lastCh = str[i];
      prefix.push_back(lastCh);

      TrieNode *curr = prev->child[lastCh - 'a'];

      if (curr == NULL)
      {
        break;
      }

      vector<string> temp;
      printUtil(curr, prefix, temp);
      output.push_back(temp);
      temp.clear();
      prev = curr;
    }
    return output;
  }
};

vector<vector<string>> phoneDirectory(vector<string> &contactList, string &queryStr)
{
  Trie *t = new Trie();

  for (auto it : contactList)
  {
    t->insert(it);
  }

  return t->getSuggestions(queryStr);
}