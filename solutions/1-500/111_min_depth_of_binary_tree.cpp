/* https://leetcode.com/problems/minimum-depth-of-binary-tree
111. Minimum Depth of Binary Tree
Easy
Tree Recursion
*/
class Solution
{
public:
    int minDepth(TreeNode *root)
    {
        if (!root)
            return 0;
        if (!root->left && !root->right)
            return 1;
        else if (root->left && root->right)
            return 1 + min(minDepth(root->left), minDepth(root->right));
        else if (root->left)
            return 1 + minDepth(root->left);
        return 1 + minDepth(root->right);
    }
};