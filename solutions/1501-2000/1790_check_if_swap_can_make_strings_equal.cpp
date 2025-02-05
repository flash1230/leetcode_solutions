/* https://leetcode.com/problems/check-if-one-string-swap-can-make-strings-equal/
1790. Check if One String Swap Can Make Strings Equal
Easy
*/
class Solution
{
public:
    bool areAlmostEqual(string s1, string s2)
    {
        int un1 = -1, un2 = -2;
        for (int i = 0; i < s1.length(); i++)
        {
            if (s1[i] == s2[i])
                continue;
            else
            {
                if (un2 > 0)
                    return false;
                else if (un1 >= 0)
                {
                    if (s1[un1] == s2[i] && s1[i] == s2[un1])
                        un2 = i;
                    else
                        return false;
                }
                else
                    un1 = i;
            }
        }
        if (un1 >= 0 && un2 < 0)
            return false;
        return true;
    }
};