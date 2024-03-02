float sjf(int n, vector<int> &arrivalTime, vector<int> &burstTime)
{
  // Create a vector of pairs to store arrival and burst times.
  vector<pair<int, int>> qu;

  // Populate the vector with input arrivalTime and burstTime.
  for (int i = 0; i < n; i++)
  {
    qu.push_back({arrivalTime[i], burstTime[i]});
  }

  // Sort the vector in descending order based on arrival time.
  sort(qu.begin(), qu.end(), greater<pair<int, int>>());

  // Create a min-priority queue (heap) to store jobs based on burst time and arrival time.
  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> ready;

  // Get the job with the highest arrival time (last element).
  auto top = qu.back();
  qu.pop_back();

  // Push the job with the least arrival time to the priority queue.
  ready.push({top.second, top.first});

  int t = top.first; // Actual time.
  float av = 0;      // Time that jobs are waiting. Initialized to 0.

  // While there are jobs in the priority queue.
  while (!ready.empty())
  {
    auto top = ready.top();
    ready.pop();

    // Calculate waiting time for the current job and update the actual time.
    av += t - top.second;
    t += top.first;

    // Iterate through the remaining jobs in the arrival list.
    auto it = qu.begin();

    // Insert and remove the jobs from the arrival list whose arrival time is less than or equal to the current time.
    while (it != qu.end())
    {
      if ((*it).first <= t)
      {
        ready.push({(*it).second, (*it).first}); // Push to the priority queue.
        qu.erase(it);                            // Remove from the arrival list.
      }
      else
      {
        it++;
      }
    }
  }

  // Return the average waiting time as a float.
  return (float)(av / n);
}
