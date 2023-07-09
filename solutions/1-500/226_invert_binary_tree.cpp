/* https://leetcode.com/problems/invert-binary-tree
226. Invert Binary Tree
Easy
DFS
*/
class Solution
{
public:
    TreeNode *invertTree(TreeNode *root)
    {
        stack<TreeNode *> st;
        TreeNode *init = root;
        st.push(root);
        while (!st.empty() && st.top() != NULL)
        {
            TreeNode *temp = st.top();
            if (temp->left && temp->right)
                swap(st.top()->left, st.top()->right);
            else if (temp->left)
            {
                st.top()->right = st.top()->left;
                st.top()->left = NULL;
            }
            else
            {
                st.top()->left = st.top()->right;
                st.top()->right = NULL;
            }
            st.pop();
            if (temp->left != NULL)
                st.push(temp->left);
            if (temp->right != NULL)
                st.push(temp->right);
        }
        return init;
    }
};