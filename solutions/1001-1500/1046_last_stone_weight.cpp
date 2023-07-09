/* https://leetcode.com/problems/last-stone-weight/
1046. Last Stone Weight
Easy
Priority Queue
*/
class Solution
{
public:
    int lastStoneWeight(vector<int> &stones)
    {
        priority_queue<int> pq;
        if (stones.size() == 1)
            return stones[0];
        for (auto i : stones)
            pq.push(i);
        while (1)
        {
            int st1 = pq.top();
            pq.pop();
            int t = st1 - pq.top();
            pq.pop();
            if (t)
                pq.push(t);
            if (pq.empty())
                return 0;
            if (pq.size() == 1)
                return pq.top();
        }
        return 0;
    }
};