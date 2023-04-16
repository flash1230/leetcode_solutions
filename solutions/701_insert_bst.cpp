/* https://leetcode.com/problems/insert-into-a-binary-search-tree/
701. Insert into a Binary Search Tree
Medium
*/
class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        TreeNode* node = new TreeNode(val);
        if(!root) {
            return node;
        }
        TreeNode* search = root;
        while(true) {
            if(val > search->val) {
                if(!search->right){
                    search->right = node;
                    return root;
                }
                search = search->right;
            }
            else {
                if(!search->left){
                    search->left = node;
                    return root;
                }
                search = search->left;
            }
        }
        return root;
    }
};