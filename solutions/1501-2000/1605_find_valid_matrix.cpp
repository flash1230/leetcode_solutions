/* https://leetcode.com/problems/find-valid-matrix-given-row-and-column-sums
1605. Find Valid Matrix Given Row and Column Sums
Medium
Greedy
*/
class Solution1
{
public:
    vector<vector<int>> restoreMatrix(vector<int> &rowSum, vector<int> &colSum)
    {
        vector<vector<int>> ans(rowSum.size(), vector<int>(colSum.size(), 0));
        int i = 0, j = 0;
        while (i < rowSum.size() && j < colSum.size())
        {
            ans[i][j] = min(rowSum[i], colSum[j]);
            rowSum[i] -= ans[i][j];
            colSum[j] -= ans[i][j];
            rowSum[i] == 0 ? i++ : j++;
        }
        return ans;
    }
};

class Solution2
{
public:
    vector<vector<int>> restoreMatrix(vector<int> &rowSum, vector<int> &colSum)
    {
        vector<vector<int>> ans(rowSum.size(), vector<int>(colSum.size(), 0));
        priority_queue<pair<int, int>> row;
        priority_queue<pair<int, int>> col;
        for (int i = 0; i < rowSum.size(); i++)
            row.push({-rowSum[i], i});
        for (int i = 0; i < colSum.size(); i++)
            col.push({-colSum[i], i});
        while (!row.empty() && !col.empty())
        {
            int i = row.top().second;
            int j = col.top().second;
            int val = min(-row.top().first, -col.top().first);
            ans[i][j] = val;
            if (row.top().first == col.top().first)
            {
                row.pop();
                col.pop();
            }
            else if (row.top().first > col.top().first)
            {
                row.pop();
                int t = col.top().first;
                col.pop();
                col.push({t + val, j});
            }
            else
            {
                col.pop();
                int t = row.top().first;
                row.pop();
                row.push({t + val, i});
            }
        }
        return ans;
    }
};