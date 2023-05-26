/* https://leetcode.com/problems/minimum-number-of-vertices-to-reach-all-nodes
1557. Minimum Number of Vertices to Reach All Nodes
Medium
Graph
*/
class Solution
{
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>> &edges)
    {
        vector<bool> isReachable(n, 0);
        for (auto i : edges)
        {
            isReachable[i[1]] = 1;
        }
        vector<int> ans;
        for (int i = 0; i < n; i++)
        {
            if (!isReachable[i])
                ans.push_back(i);
        }
        return ans;
    }
};