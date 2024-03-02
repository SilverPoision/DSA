/*
why dijkatras dont work on negative weights because it will end up
in a loop finding the minimum of the dist becuse every time you add a
negative weight that will become more less insted of begin
more;

why not queue instead of min heap?
because we have to always take the minimal weight from the queue or we will
have to do more unrequired changes to the dist vector
*/

class Solution
{
public:
  // Function to find the shortest distance of all the vertices
  // from the source vertex S.

  vector<int> dijkstra(int V, vector<vector<int>> adj[], int S)
  {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
    q.push({0, S});
    vector<int> dist(V, 1e9);
    dist[S] = 0;

    while (!q.empty())
    {
      int node = q.top().second;
      int wt = q.top().first;
      q.pop();

      for (auto it : adj[node])
      {
        int v = it[0];
        int w = it[1];
        if (w + wt < dist[v])
        {
          dist[v] = wt + w;
          q.push({dist[v], v});
        }
      }
    }

    return dist;
  }
};

// Using set
/*
Using set have an advantage of removeing the element that is being updated
 when found a better path;
*/
class Solution
{
public:
  // Function to find the shortest distance of all the vertices
  // from the source vertex S.

  vector<int> dijkstra(int V, vector<vector<int>> adj[], int S)
  {
    set<pair<int, int>> st;
    st.insert({0, S});
    vector<int> dist(V, 1e9);
    dist[S] = 0;

    while (!st.empty())
    {
      auto it = *(st.begin());
      int node = it.second;
      int wt = it.first;
      st.erase(it);

      for (auto it : adj[node])
      {
        int v = it[0];
        int w = it[1];
        if (wt + w < dist[v])
        {
          if (dist[v] != 1e9)
          {
            st.erase({dist[v], v});
          }

          dist[v] = wt + w;
          st.insert({dist[v], v});
        }
      }
    }

    return dist;
  }
};

// Derivatio of O(E log V) TC https://takeuforward.org/data-structure/g-34-dijkstras-algorithm-intuition-and-time-complexity-derivation/