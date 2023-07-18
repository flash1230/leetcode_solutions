/* https://leetcode.com/problems/sliding-window-maximum
239. Sliding Window Maximum
Hard
Sliding Window Priority Queue
*/
class Solution
{
public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k)
    {
        priority_queue<pair<int, int>> pq;
        for (int i = 0; i < k; i++)
            pq.push({nums[i], i});
        vector<int> ans = {pq.top().first};
        for (int i = k; i < nums.size(); i++)
        {
            pq.push({nums[i], i});
            while (pq.top().second <= i - k)
                pq.pop();
            ans.push_back(pq.top().first);
        }
        return ans;
    }
};