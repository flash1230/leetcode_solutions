/* https://leetcode.com/problems/root-equals-sum-of-children/
2236. Root Equals Sum of Children
Easy
Tree
*/
class Solution {
public:
    bool checkTree(TreeNode* root) {
        return (root->val * root->val) == ((root->left->val * root->left->val) +(root->right->val + root->right->val) + (2*(root->left->val * root->right->val)));
    }
};