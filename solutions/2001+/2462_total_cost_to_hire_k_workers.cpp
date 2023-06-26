/* https://leetcode.com/problems/total-cost-to-hire-k-workers/
2462. Total Cost to Hire K Workers
Medium
Two Pointers Priority Queue
*/
class Solution
{
public:
    long long totalCost(vector<int> &costs, int k, int candidates)
    {
        int n = costs.size();
        priority_queue<double, vector<double>, greater<double>> pq;
        int front = 0, back = n - 1;
        while (front < candidates && front < back)
        {
            pq.push(costs[front] + 0.1);
            pq.push(costs[back] + 0.2);
            front++;
            back--;
        }
        if (front == back && front < candidates)
        {
            pq.push(costs[front] + 0.1);
            front++;
        }
        long long ans = 0;
        while (k--)
        {
            ans += floor(pq.top());
            if ((pq.top() - floor(pq.top())) < 0.11)
            {
                pq.pop();
                if (front <= back)
                {
                    pq.push(costs[front] + 0.1);
                    front++;
                }
            }
            else
            {
                pq.pop();
                if (front <= back)
                {
                    pq.push(costs[back] + 0.2);
                    back--;
                }
            }
        }
        return ans;
    }
};