/* https://leetcode.com/problems/smallest-range-covering-elements-from-k-lists/
632. Smallest Range Covering Elements from K Lists
Hard
Priority Queue
*/
class Solution
{
public:
    vector<int> smallestRange(vector<vector<int>> &nums)
    {
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        int left = nums[0][0], right = nums[0][0];
        for (int i = 0; i < nums.size(); i++)
        {
            left = min(left, nums[i][0]);
            right = max(right, nums[i][0]);
            pq.push({nums[i][0], i, 0});
        }
        vector<int> ans = {left, right};
        while (1)
        {
            vector<int> t = pq.top();
            if (nums[t[1]].size() == t[2] + 1)
                break;
            int temp = nums[t[1]][t[2] + 1];
            pq.pop();
            pq.push({temp, t[1], t[2] + 1});
            left = pq.top()[0];
            right = max(right, temp);
            if ((right - left) < (ans[1] - ans[0]))
                ans = {left, right};
        }
        return ans;
    }
};