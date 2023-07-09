/* https://leetcode.com/problems/top-k-frequent-elements/
347. Top K Frequent Elements
Medium
Priority Queue Map
*/
class Solution
{
public:
    vector<int> topKFrequent(vector<int> &nums, int k)
    {
        unordered_map<int, int> fr;
        for (int i = 0; i < nums.size(); i++)
            fr[nums[i]]++;
        vector<int> res;
        priority_queue<pair<int, int>> pq;
        for (auto i : fr)
        {
            pq.push(make_pair(i.second, i.first));
            if (pq.size() > k)
                pq.pop();
        }
        for (auto i : pq)
            res.push_back(i.second);
        return res;
    }
};