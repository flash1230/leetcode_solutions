/* https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/
236. Lowest Common Ancestor of a Binary Tree
Medium
Binary Tree DFS
*/
class Solution
{
public:
    vector<TreeNode*> ans;
    bool hasIt(TreeNode* root, TreeNode* target)
    {
        if(root == target)
        {
            ans.push_back(root);
            return true;
        }
        if(root->left == NULL && root->right == NULL)
            return false;
        if(!root->left)
        {
            bool t = hasIt(root->right, target);
            if(t)
                ans.push_back(root);
            return t;
        }
        if(!root->right)
        {
            bool t = hasIt(root->left, target);
            if(t)
                ans.push_back(root);
            return t;
        }
        bool t = hasIt(root->left, target) || hasIt(root->right, target);
        if(t)
            ans.push_back(root);
        return t;
    }

    vector<TreeNode*> path(TreeNode* root, TreeNode* p)
    {
        hasIt(root, p);
        reverse(ans.begin(), ans.end());
        return ans;
    }

    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        if(p == q)
            return p;
        vector<TreeNode*> path1 = path(root, p);
        ans.clear();
        vector<TreeNode*> path2 = path(root, q);
        int i = 0;
        int n = min(path1.size(), path2.size());
        while(i < n)
        {
            if(path1[i] == path2[i])
                i++;
            else
                return path1[i-1];
        }
        return path1[i-1];
    }
};