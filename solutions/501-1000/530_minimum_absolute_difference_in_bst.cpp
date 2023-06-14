/* https://leetcode.com/problems/minimum-absolute-difference-in-bst/
530. Minimum Absolute Difference in BST
Easy
Tree
*/
class Solution
{
public:
    int ans = INT_MAX;
    int val = -1;
    int getMinimumDifference(TreeNode *root)
    {
        if (root->left)
            getMinimumDifference(root->left);
        if (val >= 0)
            ans = min(ans, root->val - val);
        val = root->val;
        if (root->right)
            getMinimumDifference(root->right);
        return ans;
    }
};