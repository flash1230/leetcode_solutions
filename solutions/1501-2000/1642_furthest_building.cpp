/* https://leetcode.com/problems/furthest-building-you-can-reach/
1642. Furthest Building You Can Reach
Medium
Greedy Priority Queue
*/
class Solution
{
public:
    int furthestBuilding(vector<int> &heights, int bricks, int ladders)
    {
        int n = heights.size();
        int diff = 0;
        priority_queue<int> pq;
        for (int i = 0; i < heights.size(); i++)
        {
            if (i == n - 1)
                return i;
            diff = heights[i + 1] - heights[i];
            if (diff > 0)
            {
                pq.push(-diff);
                if (pq.size() > ladders)
                {
                    bricks -= (-1 * pq.top());
                    if (bricks < 0)
                        return i;
                    pq.pop();
                }
            }
        }
        return n - 1;
    }
};