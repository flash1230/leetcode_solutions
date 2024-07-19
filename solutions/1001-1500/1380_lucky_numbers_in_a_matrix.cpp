/* https://leetcode.com/problems/lucky-numbers-in-a-matrix/
1380. Lucky Numbers in a Matrix
Easy
*/
class Solution
{
public:
    vector<int> luckyNumbers(vector<vector<int>> &matrix)
    {
        int rMin = INT_MIN;
        for (int i = 0; i < matrix.size(); i++)
        {
            int cur = INT_MAX;
            for (int j = 0; j < matrix[0].size(); j++)
                cur = min(cur, matrix[i][j]);
            rMin = max(cur, rMin);
        }
        int cMax = INT_MAX;
        for (int i = 0; i < matrix[0].size(); i++)
        {
            int cur = INT_MIN;
            for (int j = 0; j < matrix.size(); j++)
                cur = max(cur, matrix[j][i]);
            cMax = min(cur, cMax);
        }
        vector<int> ans;
        if (rMin == cMax)
            ans.push_back(rMin);
        return ans;
    }
};