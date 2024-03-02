#include <bits/stdc++.h>

bool compare(vector<int> &a, vector<int> &b)
{
  return a[2] > b[2];
}

vector<int> jobScheduling(vector<vector<int>> &jobs)
{
  // Write your code here
  sort(jobs.begin(), jobs.end(), compare);

  int maxi = 0;
  for (auto it : jobs)
    maxi = max(maxi, it[1]);

  vector<int> slots(maxi + 1, -1);
  int task = 0;
  maxi = 0;

  for (int i = 0; i < jobs.size(); i++)
  {
    for (int j = jobs[i][1]; j > 0; j--)
    {
      if (slots[j] == -1)
      {
        slots[j] = i;
        task++;
        maxi += jobs[i][2];
        break;
      }
    }
  }

  return {task, maxi};
}

// set
#include <bits/stdc++.h>

bool compare(vector<int> &job1, vector<int> &job2)
{
  return job1[2] > job2[2];
}

vector<int> jobScheduling(vector<vector<int>> &jobs)
{

  sort(jobs.begin(), jobs.end(), compare);

  int maxProfit = 0;
  int numberOfJobs = 0;
  int maxDeadline = 0;

  // Find the maximum deadline among all the jobs.
  for (int i = 0; i < jobs.size(); i++)
  {
    maxDeadline = max(maxDeadline, jobs[i][1]);
  }

  // Create a set "slots".
  set<int, greater<int>> slots;

  // Insert all the elements from maxDeadline to 1 into the set.
  for (int i = maxDeadline; i > 0; i--)
  {
    slots.insert(i);
  }
  vector<int> ans;

  for (int i = 0; i < jobs.size(); i++)
  {

    // If the set is empty or the deadline is less than the last element of the set, then ignore this job.
    if (slots.size() == 0 || jobs[i][1] < *slots.rbegin())
    {
      continue;
    }

    int availableSlot = *slots.lower_bound(jobs[i][1]);
    maxProfit = maxProfit + jobs[i][2];
    numberOfJobs += 1;
    slots.erase(availableSlot);
  }

  ans.push_back(numberOfJobs);
  ans.push_back(maxProfit);
  return ans;
}