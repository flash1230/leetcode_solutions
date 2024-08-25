/* https://leetcode.com/problems/binary-tree-postorder-traversal/
145. Binary Tree Postorder Traversal
Easy
Tree
*/
class Solution
{
public:
    vector<int> res;
    void postorder(TreeNode *node)
    {
        if (node == NULL)
            return;
        postorder(node->left);
        postorder(node->right);
        res.push_back(node->val);
    }
    vector<int> postorderTraversal(TreeNode *root)
    {
        postorder(root);
        return res;
    }
};