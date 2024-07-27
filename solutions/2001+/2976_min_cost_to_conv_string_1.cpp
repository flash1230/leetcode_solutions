/* https://leetcode.com/problems/minimum-cost-to-convert-string-i/
2976. Minimum Cost to Convert String I
Medium
Graph
*/
class Solution
{
public:
    long long minimumCost(string source, string target, vector<char> &original, vector<char> &changed, vector<int> &cost)
    {
        vector<vector<int>> prev(26, vector<int>(26, INT_MAX));
        vector<vector<int>> cur(26, vector<int>(26));
        for (int i = 0; i < 26; i++)
            prev[i][i] = 0;
        for (int i = 0; i < changed.size(); i++)
        {
            int a = int(original[i] - 'a');
            int b = int(changed[i] - 'a');
            prev[a][b] = min(cost[i], prev[a][b]);
        }
        for (int i = 0; i < 26; i++)
        {
            for (int j = 0; j < 26; j++)
            {
                for (int k = 0; k < 26; k++)
                {
                    if (j == i || k == i)
                        cur[j][k] = prev[j][k];
                    else
                    {
                        if (prev[j][i] == INT_MAX || prev[i][k] == INT_MAX)
                            cur[j][k] = prev[j][k];
                        else
                            cur[j][k] = min(prev[j][k], prev[j][i] + prev[i][k]);
                    }
                }
            }
            prev = cur;
        }
        long long ans = 0;
        for (int i = 0; i < source.size(); i++)
        {
            int a = int(source[i] - 'a');
            int b = int(target[i] - 'a');
            if (cur[a][b] == INT_MAX)
                return -1;
            else
                ans += cur[a][b];
        }
        return ans;
    }
};