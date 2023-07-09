/* https://leetcode.com/problems/dota2-senate
649. Dota2 Senate
Medium
*/
class Solution
{
public:
    string predictPartyVictory(string senate)
    {
        int score = 0;
        for (int i = 0; i < senate.length(); i++)
        {
            if (senate[i] == 'D')
            {
                if (score > 0)
                    senate.push_back('R');
                score--;
            }
            else
            {
                if (score < 0)
                    senate += 'D';
                score++;
            }
        }
        return score > 0 ? "Radiant" : "Dire";
    }
};