/* https://leetcode.com/problems/buddy-strings/
859. Buddy Strings
Easy
Map
*/
class Solution
{
public:
    bool buddyStrings(string s, string goal)
    {
        int l = s.length();
        if (l != goal.length())
        {
            return false;
        }
        int diff = 0;
        vector<int> frequency(26, 0);
        vector<int> frequency1(26, 0);
        vector<int> frequency2(26, 0);
        char d1, d2;
        for (int i = 0; i < l; i++)
        {
            frequency1[s[i] - 'a']++;
            frequency2[goal[i] - 'a']++;
            if (s[i] == goal[i])
            {
                frequency[s[i] - 'a']++;
            }
            else
            {
                diff++;
                d1 = s[i];
                d2 = goal[i];
            }
        }
        for (int i = 0; i < 25; i++)
        {
            if (frequency1[i] != frequency2[i])
            {
                return false;
            }
        }
        if (diff > 2 || diff == 1)
        {
            return false;
        }
        if (diff == 2)
        {
            return true;
        }
        for (int i = 0; i < 25; i++)
        {
            if (frequency[i] > 1)
            {
                return true;
            }
        }
        return false;
    }
};