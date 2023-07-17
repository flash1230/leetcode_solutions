/* https://leetcode.com/problems/balanced-binary-tree/
110. Balanced Binary Tree
Easy
Tree
*/
class Solution
{
public:
    bool ans = true;
    int height(TreeNode *root)
    {
        if (!ans || !root)
            return 0;
        int a = height(root->left);
        int t = height(root->right);
        if (abs(a - t) > 1)
            ans = false;
        return max(a, t) + 1;
    }
    bool isBalanced(TreeNode *root)
    {
        height(root);
        return ans;
    }
};