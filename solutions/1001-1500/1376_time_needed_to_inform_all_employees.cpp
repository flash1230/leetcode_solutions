/* https://leetcode.com/problems/time-needed-to-inform-all-employees
1376. Time Needed to Inform All Employees
Medium
DFS
*/
class Solution
{
public:
    unordered_map<int, vector<int>> mgr;
    vector<int> informTime;
    int dfs(int findfor)
    {
        int level = 0;
        for (int i : mgr[findfor])
            level = max(level, dfs(i));
        return informTime[findfor] + level;
    }

    int numOfMinutes(int n, int headID, vector<int> &manager, vector<int> &informTime)
    {
        this->informTime = informTime;
        for (int i = 0; i < n; i++)
        {
            if (manager[i] != -1)
                mgr[manager[i]].push_back(i);
        }
        return dfs(headID);
    }
};