/* https://leetcode.com/problems/maximum-width-of-binary-tree/description/
662. Maximum Width of Binary Tree
Medium
BFS
*/
class Solution
{
public:
    int widthOfBinaryTree(TreeNode *root)
    {
        if (!(root->left || root->right))
        {
            return 1;
        }
        unsigned long long cur = 0, res = 0;
        int el = 1;
        unsigned long long left = 0, right = 0;
        queue<pair<TreeNode *, unsigned long long>> q;
        q.push({root, 0});
        while (!q.empty())
        {
            auto p = q.front();
            if (p.first->left)
            {
                q.push({p.first->left, ((2 * p.second))});
            }
            if (p.first->right)
            {
                q.push({p.first->right, ((2 * p.second) + 1)});
            }
            q.pop();
            el--;
            if (el == 0)
            {
                right = p.second;
                cur = right + 1 - left;
                res = max(cur, res);
                el = q.size();
                if (el)
                    left = q.front().second;
            }
        }
        return res;
    }
};