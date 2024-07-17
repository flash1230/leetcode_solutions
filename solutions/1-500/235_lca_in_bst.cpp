/* https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/
235. Lowest Common Ancestor of a Binary Search Tree
Medium
BST
*/
class Solution
{
public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        int small = min(p->val, q->val);
        int big = max(p->val, q->val);
        while (true)
        {
            if (root->val == small || root->val == big || (big > root->val && root->val > small))
                return root;
            else if (root->val < small)
                root = root->right;
            else
                root = root->left;
        }
        return root;
    }
};