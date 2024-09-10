/* https://leetcode.com/problems/convert-1d-array-into-2d-array/
2022. Convert 1D Array Into 2D Array
Easy
*/
class Solution
{
public:
    vector<vector<int>> construct2DArray(vector<int> &original, int m, int n)
    {
        if (original.size() != (m * n))
        {
            vector<vector<int>> temp;
            return temp;
        }
        vector<vector<int>> ans(m, vector<int>(n));
        for (int i = 0; i < original.size(); i++)
            ans[i / n][i % n] = original[i];
        return ans;
    }
};