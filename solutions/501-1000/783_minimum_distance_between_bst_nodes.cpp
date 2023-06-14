/* https://leetcode.com/problems/minimum-distance-between-bst-nodes/
783. Minimum Distance Between BST Nodes
Easy
Tree
*/
class Solution {
public:
    int ans = INT_MAX;
    int val = -1;
    int minDiffInBST(TreeNode* root) {
        if(root->left)  minDiffInBST(root->left);
        if(val>=0)  ans = min(ans, root->val - val);
        val = root->val;
        if(root->right) minDiffInBST(root->right);
        return ans;
    }
};