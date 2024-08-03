/* https://leetcode.com/problems/second-minimum-time-to-reach-destination
2045. Second Minimum Time to Reach Destination
Hard
BFS
*/
class Solution
{
public:
    int secondMinimum(int n, vector<vector<int>> &edges, int time, int change)
    {
        vector<vector<int>> graph(n);
        for (auto i : edges)
        {
            graph[i[0] - 1].push_back(i[1] - 1);
            graph[i[1] - 1].push_back(i[0] - 1);
        }
        vector<pair<int, int>> visited(n, {0, 0});
        queue<int> bfs;
        bfs.push(0);
        visited[0] = {1, 0};
        int curr = 1, next = 0, level = 0, save = 0;
        while (1)
        {
            int a = bfs.front();
            bfs.pop();
            for (int i : graph[a])
            {
                if (visited[i].second < level + 1)
                {
                    if (i == n - 1)
                    {
                        if (visited[n - 1].first == 1)
                        {
                            save = level + 1;
                            goto out;
                        }
                    }
                    if (visited[i].first < 2)
                    {
                        bfs.push(i);
                        visited[i].first++;
                        visited[i].second = level + 1;
                        next++;
                    }
                }
            }
            curr--;
            if (curr == 0)
            {
                curr = next;
                next = 0;
                level++;
            }
        }
    out:
        int ans = time;
        for (int i = 1; i < save; i++)
        {
            int a = ans / change;
            int b = ans % change;
            if (a % 2)
                ans += (change - b);
            ans += time;
        }
        return ans;
    }
};