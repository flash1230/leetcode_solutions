/* https://leetcode.com/problems/first-completely-painted-row-or-column/
2661. First Completely Painted Row or Column
Medium
Map
*/
class Solution
{
public:
    int firstCompleteIndex(vector<int> &arr, vector<vector<int>> &mat)
    {
        int m = mat.size(), n = mat[0].size();
        vector<int> row(m, n);
        vector<int> col(n, m);
        unordered_map<int, pair<int, int>> location;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
                location[mat[i][j]] = {i, j};
        }
        for (int i = 0; i < arr.size(); i++)
        {
            pair<int, int> temp = location[arr[i]];
            row[temp.first]--;
            col[temp.second]--;
            if (row[temp.first] == 0 || col[temp.second] == 0)
                return i;
        }
        return 0;
    }
};