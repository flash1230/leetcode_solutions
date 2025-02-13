/* https://leetcode.com/problems/minimum-operations-to-exceed-threshold-value-ii/
3066. Minimum Operations to Exceed Threshold Value II
Medium
Priority Queue
*/
class Solution
{
public:
    int minOperations(vector<int> &nums, int k)
    {
        priority_queue<long, vector<long>, greater<long>> minheap;
        for (int i : nums)
            minheap.push(i);
        int count = 0;
        while (minheap.top() < k)
        {
            long a = minheap.top();
            minheap.pop();
            long b = minheap.top();
            minheap.pop();
            minheap.push(a * 2 + b);
            count++;
        }
        return count;
    }
};