/* 1751. Maximum Number of Events That Can Be Attended II
Hard
DP DFS
*/
class Solution
{
public:
    vector<vector<int>> dp;
    int onlyone(vector<vector<int>> &events)
    {
        int ans = 0;
        for (int i = 0; i < events.size(); i++)
            ans = max(ans, events[i][2]);
        return ans;
    }

    int dfs(int cur, int count, vector<vector<int>> &events)
    {
        if (count == 0 || cur == events.size())
            return 0;
        if (dp[count][cur] != -1)
            return dp[count][cur];
        int next;
        for (int i = cur + 1; i < events.size(); i++)
        {
            if (events[i][0] > events[cur][1])
            {
                next = i;
                break;
            }
        }
        dp[count][cur] = max(dfs(cur + 1, count, events), events[cur][2] + dfs(next, count - 1, events));
        return dp[count][cur];
    }

    int maxValue(vector<vector<int>> &events, int k)
    {
        if (k == 1)
            return onlyone(events);
        sort(events.begin(), events.end());
        int n = events.size();
        dp.resize(k + 1, vector<int>(n, -1));
        return dfs(0, k, events);
    }
};