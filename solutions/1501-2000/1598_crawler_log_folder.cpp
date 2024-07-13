/* https://leetcode.com/problems/crawler-log-folder/
1598. Crawler Log Folder
Easy
*/
class Solution
{
public:
    int minOperations(vector<string> &logs)
    {
        int ans = 0;
        for (string s : logs)
        {
            if (s[0] == '.' && s[1] == '.')
            {
                ans--;
                ans = max(ans, 0);
            }
            else if (s[0] == '.')
                continue;
            else
                ans++;
        }
        return ans;
    }
};