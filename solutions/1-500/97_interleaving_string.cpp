/* https://leetcode.com/problems/interleaving-string/
97. Interleaving String
Medium
*/
class Solution
{
public:
    bool isInterleave(string s1, string s2, string s3)
    {
        int n = s3.length();
        int a = s1.length();
        int b = s2.length();
        if (a + b != n)
            return false;
        bool table[a + 1][b + 1];
        table[0][0] = true;
        for (int i = 0; i <= a; i++)
        {
            for (int j = 0; j <= b; j++)
            {
                if (i == 0 && j == 0)
                    table[i][j] = true;
                else if (i == 0)
                    table[i][j] = (table[i][j - 1] && s2[j - 1] == s3[i + j - 1]);
                else if (j == 0)
                    table[i][j] = (table[i - 1][j] && s1[i - 1] == s3[i + j - 1]);
                else
                    table[i][j] = (table[i - 1][j] && s1[i - 1] == s3[i + j - 1]) || (table[i][j - 1] && s2[j - 1] == s3[i + j - 1]);
            }
        }
        return table[a][b];
    }
};