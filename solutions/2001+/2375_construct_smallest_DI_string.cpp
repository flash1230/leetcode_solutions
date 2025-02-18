/* https://leetcode.com/problems/construct-smallest-number-from-di-string/
2375. Construct Smallest Number From DI String
Medium
Greedy
*/
class Solution
{
public:
    void maker(int start, int end, int num, string &ans)
    {
        for (int i = start; i <= end; i++)
        {
            ans[i] = static_cast<char>(num + '0');
            num--;
        }
    }

    string smallestNumber(string pattern)
    {
        int n = pattern.size();
        string ans(n + 1, '1');
        int max = n + 1;
        int last = n;
        for (int i = n; i >= 0; i--)
        {
            if (pattern[i] == 'I')
            {
                maker(i + 1, last, max, ans);
                max -= (last - i);
                last = i;
            }
        }
        if (last != 0)
            maker(0, last, max, ans);
        return ans;
    }
};