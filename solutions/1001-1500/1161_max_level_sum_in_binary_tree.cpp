/* https://leetcode.com/problems/maximum-level-sum-of-a-binary-tree
1161. Maximum Level Sum of a Binary Tree
Medium
BFS Tree
*/
class Solution {
public:
    int maxLevelSum(TreeNode* root) {
        queue<TreeNode*> bfs;
        bfs.push(root);
        pair<int, int> ans = make_pair(0,INT_MIN);
        pair<int, int> cur = make_pair(1,0);
        int in_this_level = 1;
        int next_level = 0;
        while (!bfs.empty()) {
            TreeNode* temp = bfs.front();
            if(temp->left){
                next_level++;
                bfs.push(temp->left);
            }
            if(temp->right){
                next_level++;
                bfs.push(temp->right);
            }
            cur.second+=bfs.front()->val;
            bfs.pop();
            in_this_level--;
            if (!in_this_level)
            {
                if(cur.second>ans.second){
                    ans = cur;
                }
                cur=make_pair(++cur.first,0 );
                in_this_level = next_level;
                next_level = 0;
            }
        }
        return ans.first;
    }
};