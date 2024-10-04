/* https://leetcode.com/problems/minimum-time-difference/
539. Minimum Time Difference
Medium
Sorting
*/
class Solution
{
public:
    int findMinDifference(vector<string> &timePoints)
    {
        vector<int> mins;
        for (string s : timePoints)
            mins.push_back(((stoi(s.substr(0, 2)) * 60) + stoi(s.substr(3, 2))));
        sort(mins.begin(), mins.end());
        int ans = 1440 - mins.back() + mins[0];
        for (int i = 1; i < mins.size(); i++)
            ans = min(ans, mins[i] - mins[i - 1]);
        return ans;
    }
};