/* https://leetcode.com/problems/final-array-state-after-k-multiplication-operations-i/
3264. Final Array State After K Multiplication Operations I
Easy
Priority Queue
*/
class Solution
{
public:
    vector<int> getFinalState(vector<int> &nums, int k, int multiplier)
    {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        for (int i = 0; i < nums.size(); i++)
            pq.push({nums[i], i});
        while (k--)
        {
            int a = pq.top().second;
            pq.pop();
            nums[a] *= multiplier;
            pq.push({nums[a], a});
        }
        return nums;
    }
};