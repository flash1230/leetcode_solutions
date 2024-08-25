/* https://leetcode.com/problems/lemonade-change/
860. Lemonade Change
Easy
*/
class Solution
{
public:
    bool lemonadeChange(vector<int> &bills)
    {
        int five = 0, ten = 0;
        for (auto m : bills)
        {
            if (m == 5)
                five++;
            else if (m == 10)
            {
                if (five < 1)
                    return false;
                five--;
                ten++;
            }
            else if (ten && five)
            {
                ten--;
                five--;
            }
            else if (five > 2)
                five -= 3;
            else
                return false;
        }
        return true;
    }
};