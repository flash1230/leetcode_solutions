/* https://leetcode.com/problems/rotate-string/
796. Rotate String
Easy
*/
class Solution
{
public:
    bool rotateString(string s, string goal)
    {
        if (s.length() != goal.length())
            return false;
        vector<int> checkers;
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == goal[0])
                checkers.push_back(i);
        }
        for (int i = 0; i < checkers.size(); i++)
        {
            bool uni = true;
            int ot = 0;
            for (int j = checkers[i]; j < s.length(); j++)
            {
                if (s[j] != goal[ot])
                {
                    uni = false;
                    break;
                }
                else
                    ot++;
            }
            if (!uni)
                continue;
            for (int j = 0; j < checkers[i]; j++)
            {
                if (s[j] != goal[ot])
                {
                    uni = false;
                    break;
                }
                else
                    ot++;
            }
            if (uni)
                return true;
        }
        return false;
    }
};