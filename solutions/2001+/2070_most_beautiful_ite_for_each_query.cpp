/* https://leetcode.com/problems/most-beautiful-item-for-each-query/
2070. Most Beautiful Item for Each Query
Medium
Binary Search
*/
class Solution
{
public:
    vector<int> maximumBeauty(vector<vector<int>> &items, vector<int> &queries)
    {
        map<int, int> booties;
        for (auto i : items)
        {
            if (booties.contains(i[0]))
                booties[i[0]] = max(booties[i[0]], i[1]);
            else
                booties[i[0]] = i[1];
        }
        int cur_max = -1;
        for (auto i : booties)
        {
            cur_max = max(cur_max, i.second);
            booties[i.first] = cur_max;
        }
        vector<int> ans;
        for (int i : queries)
        {
            if (booties.contains(i))
            {
                ans.push_back(booties[i]);
                continue;
            }
            if (i < booties.begin()->first)
            {
                ans.push_back(0);
                continue;
            }
            auto it = booties.lower_bound(i);
            it--;
            ans.push_back(it->second);
        }
        return ans;
    }
};