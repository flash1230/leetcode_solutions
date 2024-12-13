/* https://leetcode.com/problems/find-score-of-an-array-after-marking-all-elements/
2593. Find Score of an Array After Marking All Elements
Medium
Priority Queue
*/
class Solution
{
public:
    long long findScore(vector<int> &nums)
    {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<bool> marked(nums.size(), false);
        for (int i = 0; i < nums.size(); i++)
            pq.push({nums[i], i});
        long long ans = 0;
        int marked_count = 0;
        while (marked_count != nums.size())
        {
            int ind = pq.top().second, num = pq.top().first;
            if (!marked[ind])
            {
                marked[ind] = true;
                marked_count++;
                ans += num;
                if (ind > 0 && !marked[ind - 1])
                {
                    marked[ind - 1] = true;
                    marked_count++;
                }
                if (ind + 1 < nums.size() && !marked[ind + 1])
                {
                    marked[ind + 1] = true;
                    marked_count++;
                }
                pq.pop();
            }
            else
                pq.pop();
        }
        return ans;
    }
};