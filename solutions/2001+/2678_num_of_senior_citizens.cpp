/* https://leetcode.com/problems/number-of-senior-citizens/
2678. Number of Senior Citizens
Easy
*/
class Solution
{
public:
    int countSeniors(vector<string> &details)
    {
        int ans = 0;
        for (auto i : details)
        {
            if ((int(i[11]) * 10 + int(i[12])) > 60)\
                ans++;
        }
        return ans;
    }
};