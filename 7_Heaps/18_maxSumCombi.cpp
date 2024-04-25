vector<int> Solution::solve(vector<int> &A, vector<int> &B, int C)
{
  priority_queue<pair<int, pair<int, int>>> maxi;
  int n = A.size();
  int m = B.size();
  set<pair<int, int>> s;
  vector<int> ans;

  sort(A.begin(), A.end());
  sort(B.begin(), B.end());

  maxi.push({A[n - 1] + B[m - 1], {n - 1, m - 1}});
  s.insert({n - 1, m - 1});

  for (int count = 0; count < C; count++)
  {
    pair<int, pair<int, int>> top = maxi.top();
    maxi.pop();

    ans.push_back(top.first);

    int i = top.second.first;
    int j = top.second.second;

    pair<int, int> temp = {i - 1, j};

    if (s.find(temp) == s.end())
    {
      maxi.push({A[i - 1] + B[j], {i - 1, j}});
      s.insert(temp);
    }

    temp = {i, j - 1};

    if (s.find(temp) == s.end())
    {
      maxi.push({A[i] + B[j - 1], {i, j - 1}});
      s.insert(temp);
    }
  }

  return ans;
}
