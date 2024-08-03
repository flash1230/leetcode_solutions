/* https://leetcode.com/problems/count-number-of-teams/
1395. Count Number of Teams
Medium
DP
*/
class Solution
{
public:
    int numTeams(vector<int> &rating)
    {
        int ans = 0;
        for (int m = 0; m < rating.size(); m++)
        {
            int sl = 0, sr = 0, ll = 0, lr = 0;
            for (int i = 0; i < m; i++)
            {
                if (rating[i] < rating[m])
                    sl++;
                else if (rating[i] > rating[m])
                    ll++;
            }
            for (int i = m + 1; i < rating.size(); i++)
            {
                if (rating[i] > rating[m])
                    lr++;
                else if (rating[i] < rating[m])
                    sr++;
            }
            ans += (sl * lr) + (ll * sr);
        }
        return ans;
    }
};