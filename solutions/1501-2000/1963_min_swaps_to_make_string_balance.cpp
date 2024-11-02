/* https://leetcode.com/problems/minimum-number-of-swaps-to-make-the-string-balanced/
1963. Minimum Number of Swaps to Make the String Balanced
Medium
*/
class Solution
{
public:
    int minSwaps(string s)
    {
        int count = 0;
        int extra = 0;
        for (int i = 0; i < s.length(); i++)
            s[i] == '[' ? count++ : count > 0 ? count-- : extra++;
        return (extra + 1) / 2;
    }
};