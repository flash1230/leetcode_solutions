/* https://leetcode.com/problems/find-the-city-with-the-smallest-number-of-neighbors-at-a-threshold-distance/
1334. Find the City With the Smallest Number of Neighbors at a Threshold Distance
Medium
Graph
*/
class Solution
{
public:
    int findTheCity(int n, vector<vector<int>> &edges, int distanceThreshold)
    {
        vector<vector<int>> prev(n, vector<int>(n, 10001));
        vector<vector<int>> cur(n, vector<int>(n));
        for (vector<int> i : edges)
        {
            prev[i[0]][i[1]] = i[2];
            prev[i[1]][i[0]] = i[2];
        }
        for (int i = 0; i < n; i++)
            prev[i][i] = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                for (int k = 0; k < n; k++)
                {
                    if (j == i || k == i)
                        cur[j][k] = prev[j][k];
                    else
                        cur[j][k] = min(prev[j][k], prev[j][i] + prev[i][k]);
                }
            }
            prev = cur;
        }
        int ans, val = n + 1;
        for (int i = 0; i < n; i++)
        {
            int dis = 0;
            for (int j = 0; j < n; j++)
            {
                if (cur[i][j] <= distanceThreshold)
                    dis++;
            }
            if (dis <= val)
            {
                ans = i;
                val = dis;
            }
        }
        return ans;
    }
};