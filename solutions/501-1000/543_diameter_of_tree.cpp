/* https://leetcode.com/problems/diameter-of-binary-tree
543. Diameter of Binary Tree
Easy
Tree
*/
class Solution
{
public:
    int count = 0;
    
    int maxDepth(TreeNode *root)
    {
        if (!root->left && !root->right)
            return 0;
        else if (!root->left)
        {
            int t = maxDepth(root->right);
            count = max(count, t + 1);
            return t + 1;
        }
        else if (!root->right)
        {
            int t = maxDepth(root->left);
            count = max(count, t + 1);
            return t + 1;
        }
        else
        {
            int a = maxDepth(root->right);
            int t = maxDepth(root->left);
            count = max(count, a + t + 2);
            return max(a, t) + 1;
        }
    }

    int diameterOfBinaryTree(TreeNode *root)
    {
        maxDepth(root);
        return count;
    }
};