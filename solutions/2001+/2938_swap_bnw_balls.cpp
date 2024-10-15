/* https://leetcode.com/problems/separate-black-and-white-balls/
2938. Separate Black and White Balls
Medium
*/
class Solution
{
public:
    long long minimumSteps(string s)
    {
        long long ans = 0;
        int n = s.length() - 1;
        int count = 0;
        while (n >= 0)
        {
            if (s[n] == '0')
                count++;
            else
                ans += count;
            n--;
        }
        return ans;
    }
};