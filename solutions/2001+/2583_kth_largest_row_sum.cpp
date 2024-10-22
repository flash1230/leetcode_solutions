/* https://leetcode.com/problems/kth-largest-sum-in-a-binary-tree/
2583. Kth Largest Sum in a Binary Tree
Medium
Tree BFS
*/
class Solution
{
public:
    long long kthLargestLevelSum(TreeNode *root, int k)
    {
        queue<TreeNode *> bfs;
        bfs.push(root);
        vector<long long> rowSum;
        long long cur = 0;
        int in_this_level = 1;
        int next_level = 0;
        while (!bfs.empty())
        {
            TreeNode *temp = bfs.front();
            if (temp->left)
            {
                next_level++;
                bfs.push(temp->left);
            }
            if (temp->right)
            {
                next_level++;
                bfs.push(temp->right);
            }
            cur += bfs.front()->val;
            bfs.pop();
            in_this_level--;
            if (!in_this_level)
            {
                rowSum.push_back(cur);
                cur = 0;
                in_this_level = next_level;
                next_level = 0;
            }
        }
        if (rowSum.size() < k)
            return -1;
        sort(rowSum.begin(), rowSum.end());
        return rowSum[rowSum.size() - k];
    }
};