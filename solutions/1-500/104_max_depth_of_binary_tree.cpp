/*https://leetcode.com/problems/maximum-depth-of-binary-tree
104. Maximum Depth of Binary Tree
Easy
Tree
*/
class Solution
{
public:
    int maxDepth(TreeNode *root)
    {
        if (root == NULL)
            return 0;
        int left = 0, right = 0;
        if (root->right != NULL)
            right = 1 + maxDepth(root->right);
        else
            right++;
        if (root->left != NULL)
            left = 1 + maxDepth(root->left);
        else
            left++;
        return max(left, right);
    }
};