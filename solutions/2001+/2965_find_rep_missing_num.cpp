/* https://leetcode.com/problems/find-missing-and-repeated-values/
2965. Find Missing and Repeated Values
Easy
*/
class Solution
{
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>> &grid)
    {
        int a = grid.size();
        unordered_set<int> h;
        for (int i = 1; i <= (a * a); i++)
            h.insert(i);
        for (int i = 0; i < a; i++)
        {
            for (int j = 0; j < a; j++)
            {
                if (h.contains(grid[i][j]))
                    h.erase(grid[i][j]);
                else
                    h.insert(grid[i][j]);
            }
        }
        vector<int> ans;
        for (auto i : h)
            ans.push_back(i);
        return ans;
    }
};