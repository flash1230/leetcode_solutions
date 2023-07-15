/* https://leetcode.com/problems/find-eventual-safe-states
802. Find Eventual Safe States
Medium
DFS
*/
class Solution
{
public:
    bool dfs(vector<vector<int>> &adj, int src, vector<bool> &vis, vector<bool> &recst)
    {
        vis[src] = true;
        recst[src] = true;
        for (int x : adj[src])
        {
            if (vis[x] == false && dfs(adj, x, vis, recst))
                return true;
            else if (recst[x] == true)
                return true;
        }
        recst[src] = false;
        return false;
    }
    
    vector<int> eventualSafeNodes(vector<vector<int>> &graph)
    {
        int n = graph.size();
        vector<vector<int>> adj(n);
        for (int i = 0; i < graph.size(); i++)
        {
            for (int j = 0; j < graph[i].size(); j++)
                adj[i].push_back(graph[i][j]);
        }
        vector<bool> visited(n, false);
        vector<bool> rec(n, false);
        for (int i = 0; i < n; i++)
            if (!visited[i])
                dfs(adj, i, visited, rec);
        vector<int> ans;
        for (int i = 0; i < rec.size(); i++)
        {
            if (!rec[i])
                ans.push_back(i);
        }
        return ans;
    }
};