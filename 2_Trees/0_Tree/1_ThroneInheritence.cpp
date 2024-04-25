class Tree
{
public:
  // https://leetcode.com/problems/throne-inheritance/
  vector<Tree *> childs;
  string name;
  bool isAlive;
  bool isEmpty;

  Tree(string name)
  {
    this->name = name;
    this->isEmpty = true;
    this->isAlive = true;
  }

  void addChild(string name)
  {
    Tree *child = new Tree(name);
    childs.push_back(child);
    this->isEmpty = false;
  }
};

class ThroneInheritance
{
public:
  Tree *h;
  unordered_map<string, Tree *> hash;

  void dfs(Tree *root, vector<string> &str)
  {
    if (root->isAlive)
      str.push_back(root->name);

    if (root->isEmpty)
      return;

    for (int i = 0; i < root->childs.size(); i++)
    {
      dfs(root->childs[i], str);
    }
  }

  ThroneInheritance(string kingName)
  {
    h = new Tree(kingName);
    hash[kingName] = h;
  }

  void birth(string parentName, string childName)
  {
    hash[parentName]->addChild(childName);
    hash[childName] = hash[parentName]->childs.back();
  }

  void death(string name)
  {
    hash[name]->isAlive = false;
  }

  vector<string> getInheritanceOrder()
  {
    vector<string> ans;
    dfs(h, ans);

    return ans;
  }
};
