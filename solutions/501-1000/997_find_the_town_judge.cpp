/* https://leetcode.com/problems/find-the-town-judge/
997. Find the Town Judge
Easy
*/
class Solution
{
public:
    int findJudge(int n, vector<vector<int>> &trust)
    {
        vector<bool> can_be_judge(n, true);
        for (auto i : trust)
            can_be_judge[i[0] - 1] = false;
        int ans = -1;
        for (int i = 0; i < n; i++)
        {
            if (can_be_judge[i])
            {
                ans = i + 1;
                break;
            }
        }
        if (ans == -1)
            return -1;
        vector<bool> trusted_by(n, false);
        trusted_by[ans - 1] = true;
        for (auto i : trust)
        {
            if (i[1] == ans)
                trusted_by[i[0] - 1] = true;
        }
        for (bool i : trusted_by)
        {
            if (!i)
                return -1;
        }
        return ans;
    }
};