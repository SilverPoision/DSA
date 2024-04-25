typedef pair<int, int> pi;

vector<int> replaceWithRank(vector<int> &arr, int n)
{
  // Write your code here.
  priority_queue<pi, vector<pi>, greater<pi>> min;

  for (int i = 0; i < arr.size(); i++)
  {
    min.push({arr[i], i});
  }

  vector<int> ans(arr.size());

  int currRank = 0, currEle = INT_MIN;

  while (!min.empty())
  {
    pi p = min.top();
    min.pop();

    if (currEle == p.first)
    {
      ans[p.second] = currRank;
    }
    else
    {
      ans[p.second] = ++currRank;
      currEle = p.first;
    }
  }

  return ans;
}

bool flag = true;
if (flag && !min.empty())
{
  char mini = min.top();

  if (hash.find(mini) != hash.end())
  {
    if (k + hash[mini] > ans)
    {
      if (k + hash[max.top()] > ans)
      {
        flag = !flag;
        continue;
      }
      ans++;
    }
  }

  min.pop();
  ans++;
  hash[mini] = ans;
}
else if (!max.empty())
{
  char maxi = max.top();

  if (hash.find(maxi) != hash.end())
  {
    if (k + hash[maxi] > ans)
    {
      if (k + hash[min.top()] > ans)
      {
        flag = !flag;
        continue;
      }
      ans++;
    }
  }

  max.pop();
  ans++;
  hash[maxi] = ans;
}
flag = !flag;