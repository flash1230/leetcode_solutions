/* https://leetcode.com/problems/count-days-without-meetings/
3169. Count Days Without Meetings
Medium
Sorting
*/
class Solution
{
public:
    int countDays(int days, vector<vector<int>> &meetings)
    {
        int lastdone = 0;
        int ans = 0;
        sort(meetings.begin(), meetings.end());
        for (int i = 0; i < meetings.size(); i++)
        {
            if (lastdone + 1 < meetings[i][0])
                ans += meetings[i][0] - lastdone - 1;
            lastdone = max(lastdone, meetings[i][1]);
        }
        if (lastdone < days)
            ans += days - lastdone;
        return ans;
    }
};