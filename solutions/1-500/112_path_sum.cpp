/* https://leetcode.com/problems/path-sum/
112. Path Sum
Easy
Tree DFS
*/
class Solution
{
public:
    bool hasPathSum(TreeNode *root, int targetSum)
    {
        if (!root)
            return false;
        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty())
        {
            if (!q.front()->left && !q.front()->right)
            {
                if (q.front()->val == targetSum)
                    return true;
                else
                {
                    q.pop();
                    continue;
                }
            }
            TreeNode *temp = q.front();
            if (temp->right)
            {
                temp->right->val += temp->val;
                q.push(temp->right);
            }
            if (temp->left)
            {
                temp->left->val += temp->val;
                q.push(temp->left);
            }
            q.pop();
        }
        return false;
    }
};