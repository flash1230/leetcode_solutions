/* https://leetcode.com/problems/kth-largest-element-in-an-array/
215. Kth Largest Element in an Array
Medium
Priority Queue
*/
class Solution
{
public:
    int findKthLargest(vector<int> &nums, int k)
    {
        priority_queue<int, vector<int>, greater<int>> minheap;
        for (int i : nums)
        {
            if (minheap.size() < k)
                minheap.push(i);
            else
            {
                if (minheap.top() < i)
                {
                    minheap.pop();
                    minheap.push(i);
                }
            }
        }
        return minheap.top();
    }
};