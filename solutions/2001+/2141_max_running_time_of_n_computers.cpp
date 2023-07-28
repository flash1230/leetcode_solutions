/* https://leetcode.com/problems/maximum-running-time-of-n-computers/
2141. Maximum Running Time of N Computers
Hard
*/
class Solution
{
public:
    long long maxRunTime(int n, vector<int> &batteries)
    {
        if (n > batteries.size())
            return 0;
        long long l = INT_MAX, r, sum = 0;
        for (long long i : batteries)
        {
            l = min(l, i);
            sum += i;
        }
        if (n == batteries.size())
            return l;
        r = sum / n;
        while (l < r)
        {
            long long target = r - (r - l) / 2;
            long long extra = 0;
            for (long long i : batteries)
                extra += min(i, target);
            if (extra >= long(n) * target)
                l = target;
            else
                r = target - 1;
        }
        return l;
    }
};