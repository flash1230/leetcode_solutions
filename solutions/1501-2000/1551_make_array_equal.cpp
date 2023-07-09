/* https://leetcode.com/problems/minimum-operations-to-make-array-equal/
1551. Minimum Operations to Make Array Equal
Medium
Math
*/
class Solution
{
public:
    int minOperations(int n)
    {
        int ans = n * n / 2;
        for (int i = 0; i < (n / 2); i++)
            ans -= 2 * i + 1;
        return ans;
    }
};