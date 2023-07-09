/* https://leetcode.com/problems/path-with-maximum-probability
1514. Path with Maximum Probability
Medium
Graph Djikstra Bellman Ford
*/
class Solution
{
public:
    double maxProbability(int n, vector<vector<int>> &edges, vector<double> &succProb, int start, int end)
    {
        vector<pair<int, double>> adj[n];
        vector<double> probs(n, 0.0);
        queue<pair<int, double>> q;
        for (int i = 0; i < edges.size(); i++)
        {
            adj[edges[i][0]].push_back({edges[i][1], succProb[i]});
            adj[edges[i][1]].push_back({edges[i][0], succProb[i]});
        }
        probs[start] = 1.0;
        q.push({start, 1});
        while (!q.empty())
        {
            int node = q.front().first;
            double d = q.front().second;
            q.pop();
            for (auto it : adj[node])
            {
                if (d * it.second > probs[it.first])
                {
                    probs[it.first] = d * it.second;
                    q.push({it.first, probs[it.first]});
                }
            }
        }
        if (probs[end] == 1e9)
            return 0;
        return probs[end];
    }
};