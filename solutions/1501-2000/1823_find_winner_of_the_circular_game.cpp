/* https://leetcode.com/problems/find-the-winner-of-the-circular-game
1823. Find the Winner of the Circular Game
Medium
Queue
*/
class Solution
{
public:
    int findTheWinner(int n, int k)
    {
        queue<int> lis;
        for (int i = 1; i <= n; i++)
            lis.push(i);
        while (lis.size() > 1)
        {
            for (int i = 1; i < k; i++)
            {
                int t = lis.front();
                lis.pop();
                lis.push(t);
            }
            lis.pop();
        }
        return lis.front();
    }
};