/* https://leetcode.com/problems/evaluate-division/
399. Evaluate Division
Medium
DFS
*/
class Solution
{
public:
    void dfs(string s, string e, map<string, double> &mp, map<string, vector<string>> &graph, double &val, map<string, int> &vis, bool &check)
    {
        vis[s] = 1;
        if (check == true)
            return;
        for (auto it : graph[s])
        {
            if (vis[it] != 1)
            {
                val *= mp[s + "->" + it];
                if (e == it)
                {
                    check = true;
                    return;
                }
                dfs(it, e, mp, graph, val, vis, check);
                if (check == true)
                    return;
                else
                    val /= mp[s + "->" + it];
            }
        }
    }
    
    vector<double> calcEquation(vector<vector<string>> &equations, vector<double> &values, vector<vector<string>> &queries)
    {
        vector<double> ans;
        map<string, double> mp;
        map<string, vector<string>> graph;
        for (int i = 0; i < equations.size(); i++)
        {
            string u = equations[i][0];
            string v = equations[i][1];
            mp[u + "->" + v] = values[i];
            mp[v + "->" + u] = 1 / values[i];
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        for (int i = 0; i < queries.size(); i++)
        {
            string s = queries[i][0];
            string e = queries[i][1];
            if (graph.find(s) == graph.end() || graph.find(e) == graph.end())
                ans.push_back(-1);
            else
            {
                double val = 1;
                map<string, int> vis;
                bool check = false;
                if (s == e)
                    check = true;
                else
                    dfs(s, e, mp, graph, val, vis, check);
                if (check == true)
                    ans.push_back(val);
                else
                    ans.push_back(-1);
            }
        }
        return ans;
    }
};