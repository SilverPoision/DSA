class Solution
{
public:
  // try to solve it using bit masking
  //  https://leetcode.com/problems/maximum-product-of-the-length-of-two-palindromic-subsequences/
  bool checkPali(string &s, vector<int> &out)
  {
    int i = 0, j = out.size() - 1;

    while (i < j)
    {
      if (s[out[i]] != s[out[j]])
        return false;
      i++;
      j--;
    }

    return true;
  }
  void f(int i, string &s, vector<int> out, vector<vector<int>> &hash)
  {
    if (i == s.size())
    {
      if (checkPali(s, out))
      {
        hash.push_back(out);
      }
      return;
    }

    out.push_back(i);
    f(i + 1, s, out, hash);
    out.pop_back();
    f(i + 1, s, out, hash);
  }

  bool checkDisjoint(vector<int> &a, vector<int> &b)
  {
    for (int i = 0; i < a.size(); i++)
    {
      for (int j = 0; j < b.size(); j++)
      {
        if (a[i] == b[j])
          return false;
      }
    }

    return true;
  }

  int maxProduct(string s)
  {
    vector<vector<int>> hash;
    vector<int> out;
    f(0, s, out, hash);

    int maxi = 0;

    for (int i = 0; i < hash.size(); i++)
    {
      for (int j = i + 1; j < hash.size(); j++)
      {
        if (checkDisjoint(hash[i], hash[j]))
        {
          maxi = max(maxi, (int)hash[i].size() * (int)hash[j].size());
        }
      }
    }

    return maxi;
  }
};