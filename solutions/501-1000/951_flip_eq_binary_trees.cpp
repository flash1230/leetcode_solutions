/* https://leetcode.com/problems/flip-equivalent-binary-trees/
951. Flip Equivalent Binary Trees
Medium
Tree
*/
class Solution
{
public:
    bool childrenEqual(TreeNode *root1, TreeNode *root2)
    {
        int a = root1->left ? root1->left->val : -1;
        int b = root1->right ? root1->right->val : -1;
        int c = root2->left ? root2->left->val : -1;
        int d = root2->right ? root2->right->val : -1;
        if ((a == c && b == d) || (a == d) && (b == c))
            return true;
        return false;
    }
    bool flipEquiv(TreeNode *root1, TreeNode *root2)
    {
        if (!root1 && !root2)
            return true;
        if (!root1 || !root2 || root1->val != root2->val)
            return false;
        queue<TreeNode *> bfs1, bfs2;
        bfs1.push(root1);
        bfs2.push(root2);
        while (!bfs1.empty())
        {
            if (!childrenEqual(bfs1.front(), bfs2.front()))
                return false;
            if (bfs1.front()->left)
            {
                bfs1.push(bfs1.front()->left);
                if (bfs2.front()->right && bfs2.front()->right->val == bfs1.front()->left->val)
                    bfs2.push(bfs2.front()->right);
                else
                    bfs2.push(bfs2.front()->left);
            }
            if (bfs1.front()->right)
            {
                bfs1.push(bfs1.front()->right);
                if (bfs2.front()->right && bfs2.front()->right->val == bfs1.front()->right->val)
                    bfs2.push(bfs2.front()->right);
                else
                    bfs2.push(bfs2.front()->left);
            }
            bfs1.pop();
            bfs2.pop();
        }
        return true;
    }
};