class Solution
{
public:
    // https://leetcode.com/problems/path-with-maximum-probability/description/?envType=daily-question&envId=2024-08-27
    double maxProbability(int n, vector<vector<int>> &edges, vector<double> &succProb, int start_node, int end_node)
    {
        unordered_map<int, vector<vector<double>>> adj;

        for (int i = 0; i < edges.size(); i++)
        {
            adj[edges[i][0]].push_back({(double)edges[i][1], succProb[i]});
            adj[edges[i][1]].push_back({(double)edges[i][0], succProb[i]});
        }

        priority_queue<pair<double, int>> pq;
        vector<bool> vis(n + 1, false);

        pq.push({1, start_node});

        while (!pq.empty())
        {
            auto [w, node] = pq.top();
            pq.pop();

            if (vis[node])
                continue;
            if (node == end_node)
                return w;
            vis[node] = true;

            for (auto it : adj[node])
            {
                if (!vis[it[0]])
                {
                    pq.push({(double)w * it[1], it[0]});
                }
            }
        }

        return 0;
    }
};