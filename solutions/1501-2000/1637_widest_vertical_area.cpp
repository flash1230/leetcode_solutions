/* https://leetcode.com/problems/widest-vertical-area-between-two-points-containing-no-points/
1637. Widest Vertical Area Between Two Points Containing No Points
Medium
Priority Queue
*/
class Solution
{
public:
    int maxWidthOfVerticalArea(vector<vector<int>> &points)
    {
        priority_queue<int> pq;
        for (int i = 0; i < points.size(); i++)
            pq.push(points[i][0]);
        int ans = 0;
        while (!pq.empty())
        {
            int temp = pq.top();
            pq.pop();
            ans = max(ans, temp - pq.top());
        }
        return ans;
    }
};