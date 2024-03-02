void sortedInsert(stack<int> &s, int x)
{
  if (s.empty() || x > s.top())
  {
    s.push(x);
    return;
  }

  int temp = s.top();
  s.pop();
  sortedInsert(s, x);

  s.push(temp);
}

void SortedStack ::sort()
{
  // Your code here
  if (!s.empty())
  {
    int x = s.top();
    s.pop();

    sort();

    sortedInsert(s, x);
  }
}