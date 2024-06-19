class Node
{
public:
  // https://leetcode.com/problems/replace-words/?envType=daily-question&envId=2024-06-07
  Node *child[26];
  bool isTerminal;
  Node()
  {
    for (int i = 0; i < 26; i++)
    {
      child[i] = nullptr;
    }
    isTerminal = false;
  }
};

class Trie
{
public:
  Node *root;
  Trie() { root = new Node(); }

  void insertUtil(Node *root, string word)
  {
    if (word.size() == 0)
    {
      root->isTerminal = true;
      return;
    }

    int idx = word[0] - 'a';
    Node *child;

    if (root->child[idx])
    {
      child = root->child[idx];
    }
    else
    {
      child = new Node();
      root->child[idx] = child;
    }

    insertUtil(child, word.substr(1));
  }

  void insert(string word) { insertUtil(root, word); }

  string searchUtil(Node *child, string word, string out)
  {
    if (word.size() == 0 && child->isTerminal == false)
      return "";
    if (child->isTerminal)
    {
      return out;
    }

    int idx = word[0] - 'a';

    if (child->child[idx])
    {
      return searchUtil(child->child[idx], word.substr(1), out + word[0]);
    }
    return "";
  }

  string search(string word) { return searchUtil(root, word, ""); }
};

class Solution
{
public:
  string replaceWords(vector<string> &d, string s)
  {
    Trie t;
    for (auto it : d)
    {
      t.insert(it);
    }

    string temp;
    stringstream ss(s);

    string ans = "";

    while (getline(ss, temp, ' '))
    {
      string res = t.search(temp);
      if (res.size() == 0)
        ans += temp;
      else
        ans += res;
      ans += " ";
    }

    ans.pop_back();
    return ans;
  }
};