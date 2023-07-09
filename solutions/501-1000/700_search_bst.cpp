/* https://leetcode.com/problems/search-in-a-binary-search-tree/
700. Search in a Binary Search Tree
Easy
*/
class Solution
{
public:
    TreeNode *searchBST(TreeNode *root, int val)
    {
        TreeNode *search = root;
        while (search)
        {
            if (search->val == val)
                return search;
            else if (search->val > val)
                search = search->left;
            else
                search = search->right;
        }
        TreeNode *node;
        return node;
    }
};