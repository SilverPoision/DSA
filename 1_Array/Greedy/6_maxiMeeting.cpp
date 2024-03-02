struct meetings
{
  int start;
  int end;
  int pos;

  meetings(int s, int e, int p)
  {
    start = s;
    end = e;
    pos = p;
  }
};

bool comparator(meetings &a, meetings &b)
{
  if (a.end == b.end)
    return a.pos < b.pos;
  return a.end < b.end;
}

int maximumMeetings(vector<int> &start, vector<int> &end)
{
  int n = start.size();

  vector<meetings> store;
  for (int i = 0; i < n; i++)
  {
    meetings nM = meetings(start[i], end[i], i);
    store.push_back(nM);
  }

  sort(store.begin(), store.end(), comparator);

  int maxi = 1;
  int limit = store[0].end;

  for (int i = 1; i < n; i++)
  {
    if (store[i].start > limit)
    {
      maxi++;
      limit = store[i].end;
    }
  }

  return maxi;
}