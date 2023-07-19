/* https://leetcode.com/problems/non-overlapping-intervals/
435. Non-overlapping Intervals
Medium
Sorting Greedy
*/
class Solution
{
public:
    int eraseOverlapIntervals(vector<vector<int>> &intervals)
    {
        int n = intervals.size();
        if(n<1)
            return 0;
        sort(intervals.begin(), intervals.end());
        int ans = 0;
        int cur_start = intervals[0][0];
        int cur_end = intervals[0][1];
        int i=1;
        while(i<n)
        {
            if(intervals[i][0]>=cur_end)
            {
                cur_end = intervals[i][1];
                cur_start = intervals[i][0];
                i++;
                continue;
            }
            if(intervals[i][1]<cur_end)
            {
                cur_end = intervals[i][1];
                cur_start = intervals[i][0];
                ans++;
                i++;
                continue;
            }
            else
            {
                i++;
                ans++;
            }
        }
        return ans;
    }
};