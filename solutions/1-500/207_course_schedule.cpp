/* https://leetcode.com/problems/course-schedule/
207. Course Schedule
Medium
Graph BFS
*/
class Solution
{
public:
    bool canFinish(int numCourses, vector<vector<int>> &prerequisites)
    {
        int n = prerequisites.size();
        if (n < 2)
            return true;
        vector<int> indegree(numCourses, 0);
        vector<vector<int>> graph(numCourses);
        for (auto i : prerequisites)
        {
            indegree[i[0]]++;
            graph[i[1]].push_back(i[0]);
        }
        queue<int> q1;
        int count = 0;
        for (int i = 0; i < numCourses; i++)
        {
            if (!indegree[i])
                q1.push(i);
        }
        if (q1.empty())
            return false;
        while (!q1.empty())
        {
            for (int i : graph[q1.front()])
            {
                indegree[i]--;
                count++;
                if (count == n)
                    return true;
                if (indegree[i] == 0)
                    q1.push(i);
            }
            q1.pop();
        }
        return false;
    }
};