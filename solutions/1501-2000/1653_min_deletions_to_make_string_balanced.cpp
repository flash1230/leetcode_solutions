/* https://leetcode.com/problems/minimum-deletions-to-make-string-balanced/
1653. Minimum Deletions to Make String Balanced
Medium
DP
*/
class Solution
{
public:
    int minimumDeletions(string s)
    {
        int n = s.length();
        vector<int> b_before(n);
        int a = 0, b = 0;
        for (int i = 0; i < n; i++)
        {
            b_before[i] = b;
            if (s[i] == 'b')
                b++;
        }
        int ans = n;
        for (int i = n - 1; i >= 0; i--)
        {
            ans = min(ans, b_before[i] + a);
            if (s[i] == 'a')
                a++;
        }
        return ans;
    }
};