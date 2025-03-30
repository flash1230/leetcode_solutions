/* https://leetcode.com/problems/partition-labels/
763. Partition Labels
Medium
Two Pointers, Map
*/
class Solution
{
public:
    vector<int> partitionLabels(string s)
    {
        vector<int> pos(26, -1);
        for (int i = 0; i < s.length(); i++)
            pos[int(s[i] - 'a')] = i;
        vector<int> ans;
        int cur = -1;
        int prev = -1;
        for (int i = 0; i < s.length(); i++)
        {
            cur = max(cur, pos[int(s[i] - 'a')]);
            if (i == cur)
            {
                ans.push_back(i - prev);
                prev = i;
            }
        }
        return ans;
    }
};