/* https://leetcode.com/problems/maximal-score-after-applying-k-operations/
2530. Maximal Score After Applying K Operations
Medium
Priority Queue
*/
class Solution
{
public:
    long long maxKelements(vector<int> &nums, int k)
    {
        long long ans = 0;
        priority_queue<int, vector<int>, greater<int>> min_pq;
        for (int i = 0; i < k && i < nums.size(); i++)
            min_pq.push(nums[i]);
        for (int i = k; i < nums.size(); i++)
        {
            if (nums[i] > min_pq.top())
            {
                min_pq.pop();
                min_pq.push(nums[i]);
            }
        }
        priority_queue<int> max_pq;
        while (!min_pq.empty())
        {
            max_pq.push(min_pq.top());
            min_pq.pop();
        }
        for (int i = 0; i < k; i++)
        {
            ans += max_pq.top();
            int temp = ceil((max_pq.top() / 3.00));
            max_pq.pop();
            max_pq.push(temp);
        }
        return ans;
    }
};