/* https://leetcode.com/problems/sort-the-people
2418. Sort the People
Easy
Sorting
*/
class Solution
{
public:
    vector<string> sortPeople(vector<string> &names, vector<int> &heights)
    {
        vector<pair<int, string>> ds;
        for (int i = 0; i < names.size(); i++)
            ds.push_back({heights[i], names[i]});
        sort(ds.begin(), ds.end());
        vector<string> ans;
        for (int i = names.size() - 1; i >= 0; i--)
            ans.push_back(ds[i].second);
        return ans;
    }
};