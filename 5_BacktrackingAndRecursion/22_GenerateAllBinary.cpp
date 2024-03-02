#include <bits/stdc++.h>
using namespace std;

void generateAll(int k, int ind, vector<string> &ans, string st)
{
  if (ind == k)
  {
    // cout << st;
    ans.push_back(st);
    return;
  }

  if (st[ind - 1] == '1')
  {
    st[ind] = '0';
    generateAll(k, ind + 1, ans, st);
  }

  if (st[ind - 1] == '0')
  {
    st[ind] = '1';
    generateAll(k, ind + 1, ans, st);
    st[ind] = '0';
    generateAll(k, ind + 1, ans, st);
  }
}

int main()
{
  int k = 2;
  vector<string> ans;
  string st = "";
  for (int i = 0; i < k; i++)
  {
    st.push_back(' ');
  }
  st[0] = '0';
  generateAll(k, 1, ans, st);
  st[0] = '1';
  generateAll(k, 1, ans, st);

  for (auto it : ans)
  {
    cout << it << " ";
  }

  return 0;
}