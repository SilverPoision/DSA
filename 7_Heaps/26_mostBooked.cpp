// My sol
#define ll long long

class Solution
{
public:
  // https://leetcode.com/problems/meeting-rooms-iii/
  int mostBooked(int n, vector<vector<int>> &m)
  {
    int size = m.size();
    priority_queue<pair<ll, int>, vector<pair<ll, int>>,
                   greater<pair<ll, int>>>
        endTime;

    priority_queue<int, vector<int>, greater<int>> r;
    for (int i = 0; i < n; i++)
      r.push(i);

    vector<int> hash(n, 0);
    sort(m.begin(), m.end());

    int i = 0;

    while (i < size)
    {
      while (endTime.size() > 0 && endTime.top().first <= m[i][0])
      {
        r.push(endTime.top().second);
        endTime.pop();
      }

      if (r.size() == 0)
      {
        auto top = endTime.top();
        endTime.pop();
        long long time = top.first;
        int room = top.second;
        hash[room]++;
        endTime.push({time + m[i][1] - m[i][0], room});
      }
      else
      {
        endTime.push({m[i][1], r.top()});
        hash[r.top()]++;
        r.pop();
      }
      i++;
    }

    int ans = -1;
    int maxi = -1e9;
    for (i = 0; i < n; i++)
    {
      if (hash[i] > maxi)
      {
        ans = i;
        maxi = hash[i];
      }
    }

    return ans;
  }
};

// Brute
class Solution
{
public:
  int mostBooked(int n, vector<vector<int>> &meetings)
  {
    int m = meetings.size();

    vector<long long> meetEndingAt(n, 0);

    vector<int> noRoomUsed(n, 0);

    sort(meetings.begin(), meetings.end());

    for (vector<int> &meet : meetings)
    {

      int start = meet[0];
      int end = meet[1];
      int duration = end - start;

      bool found = false;
      long long earliestMeetingEnd = LLONG_MAX;
      int earlyEndRoom = -1;

      for (int room = 0; room < n; room++)
      {
        if (meetEndingAt[room] <= start)
        {
          meetEndingAt[room] = end;
          found = true;
          noRoomUsed[room]++;
          break;
        }
        if (earliestMeetingEnd > meetEndingAt[room])
        {
          earliestMeetingEnd = meetEndingAt[room];
          earlyEndRoom = room;
        }
      }

      if (!found)
      {
        meetEndingAt[earlyEndRoom] += duration;
        noRoomUsed[earlyEndRoom]++;
      }
    }

    int maxRoomUsed = 0;
    int room = -1;
    for (int i = 0; i < n; i++)
    {
      if (noRoomUsed[i] > maxRoomUsed)
      {
        maxRoomUsed = noRoomUsed[i];
        room = i;
      }
    }

    return room;
  }
};
