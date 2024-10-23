/* https://leetcode.com/problems/cousins-in-binary-tree-ii/
2641. Cousins in Binary Tree II
Medium
BFS
*/
class Solution
{
public:
    TreeNode *replaceValueInTree(TreeNode *root)
    {
        queue<TreeNode *> bfs;
        bfs.push(root);
        vector<int> rowSum;
        int cur = 0;
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
        bfs.push(root);
        root->val = 0;
        int row = 0;
        in_this_level = 1;
        next_level = 0;
        while (!bfs.empty())
        {
            TreeNode *temp = bfs.front();
            cur = 0;
            if (temp->left)
            {
                next_level++;
                cur += temp->left->val;
                bfs.push(temp->left);
            }
            if (temp->right)
            {
                next_level++;
                cur += temp->right->val;
                bfs.push(temp->right);
            }
            if (temp->left)
                temp->left->val = (row + 1 == rowSum.size()) ? 0 : (rowSum[row + 1] - cur);
            if (temp->right)
                temp->right->val = (row + 1 == rowSum.size()) ? 0 : (rowSum[row + 1] - cur);
            bfs.pop();
            in_this_level--;
            if (!in_this_level)
            {
                row++;
                in_this_level = next_level;
                next_level = 0;
            }
        }
        return root;
    }
};