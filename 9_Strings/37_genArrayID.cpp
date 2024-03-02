vector<int> solve(int n, string &s)
{
  // https://www.codingninjas.com/studio/contests/weekly-contest-113/11302977/problems/30205?leftPanelTabValue=PROBLEM&customSource=studio_nav
  //  Write your code here.
  int rec = 1;
  int ans = 1;
  int i = 0;
  s = s + '#';

  while (s[i] != '#')
  {
    if (s[i] == 'I')
      ans++;
    else
    {
      ans--;
    }
    if (rec > ans && ans <= 0)
      rec = ans;
    i++;
  }

  ans = 1;
  if (rec <= 0)
    ans += abs(rec) + 1;
  vector<int> a;
  a.push_back(ans);
  i = 0;
  while (s[i] != '#')
  {
    if (s[i] == 'I')
    {
      a.push_back(++ans);
    }
    else
    {
      a.push_back(--ans);
    }
    i++;
  }

  return a;
}