class Solution
{
public:
  bool asteroidsDestroyed(int mass, vector<int> &a)
  {
    sort(a.begin(), a.end());

    long long m = mass;

    for (auto it : a)
    {
      if (it <= m)
        m += it;
      else
        return false;
    }

    return true;
  }
};

class Solution
{
public:
  // n2
  bool asteroidsDestroyed(int mass, vector<int> &a)
  {
    long long m = mass;
    vector<int> temp;

    while (a.size() != 0)
    {
      bool flag = true;
      for (int i = 0; i < a.size(); i++)
      {
        if (a[i] <= m)
        {
          m += a[i];
          flag = false;
        }
        else
        {
          if (i == a.size() - 1 && temp.size() == 0)
            return false;
          temp.push_back(a[i]);
        }
      }
      if (flag)
        return false;
      a.clear();
      swap(temp, a);
    }

    return true;
  }
};