/* https://leetcode.com/problems/take-gifts-from-the-richest-pile/
2558. Take Gifts From the Richest Pile
Easy
Priority Queue
*/
class Solution
{
public:
    long long pickGifts(vector<int> &gifts, int k)
    {
        priority_queue<int, vector<int>, greater<int>> pq;
        long long ans = 0;
        for (int i : gifts)
        {
            ans += i;
            if (pq.size() < k)
            {
                pq.push(i);
                continue;
            }
            if (pq.top() < i)
            {
                pq.pop();
                pq.push(i);
            }
        }
        priority_queue<int> mq;
        while (!pq.empty())
        {
            mq.push(pq.top());
            pq.pop();
        }
        for (int i = 0; i < k; i++)
        {
            int a = mq.top();
            mq.pop();
            ans -= (a - sqrt(a));
            mq.push(sqrt(a));
        }
        return ans;
    }
};