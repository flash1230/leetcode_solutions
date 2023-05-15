/* https://leetcode.com/problems/binary-tree-right-side-view/
199. Binary Tree Right Side View
Medium
*/
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        if(!root) {
            return ans;
        }
        queue<TreeNode*> q;
        q.push(root);
        int n = 1;
        int m = 0;
        while(!q.empty()) {
            TreeNode* temp = q.front();
            n--;
            if(n==0) {
                ans.push_back(temp->val);
            }
            if(temp->left) {
                q.push(temp->left);
                m++;
            }
            if(temp->right) {
                q.push(temp->right);
                m++;
            }
            q.pop();
            if(n==0) {
                n=m;
                m=0;
            }
        }
        return ans;
    }
};