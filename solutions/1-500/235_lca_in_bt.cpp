/* https://leetcode.com/problems/largest-rectangle-in-histogram/
235. Lowest Common Ancestor of a Binary Search Tree
Medium
*/
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        int small = min(p->val, q->val);
        int big = max(p->val, q-> val);
        while(true) {
            int a = root->val;
            if(a == small || a == big || (big > a && a > small)) {
                return root;
            }
            else if(a < small) {
                root = root->right;
            }
            else {
                root = root->left;
            }
        }
        return root;
    }
};