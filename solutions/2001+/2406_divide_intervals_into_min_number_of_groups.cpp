/* https://leetcode.com/problems/divide-intervals-into-minimum-number-of-groups/
Medium
Priority Queue Sorting
*/
class Solution1
{
public:
    int minGroups(vector<vector<int>> &intervals)
    {
        sort(intervals.begin(), intervals.end());
        priority_queue<int, vector<int>, greater<int>> ends;
        for (auto i : intervals)
        {
            if (ends.empty())
                ends.push(i[1]);
            else if (i[0] <= ends.top())
                ends.push(i[1]);
            else
            {
                ends.pop();
                ends.push(i[1]);
            }
        }
        return ends.size();
    }
};

class Solution2
{
public:
    int minGroups(vector<vector<int>> &intervals)
    {
        int min_val = 1000001, max_val = -1;
        for (auto i : intervals)
        {
            min_val = min(min_val, i[0]);
            max_val = max(max_val, i[1]);
        }
        vector<int> points(max_val + 2, 0);
        for (auto i : intervals)
        {
            points[i[0]]++;
            points[i[1] + 1]--;
        }
        int cur_inters = 0;
        int ans = 0;
        for (int i = min_val; i <= max_val; i++)
        {
            cur_inters += points[i];
            ans = max(ans, cur_inters);
        }
        return ans;
    }
};