/* https://leetcode.com/problems/delete-nodes-and-return-forest/
1110. Delete Nodes And Return Forest
Medium
Tree DFS
*/
class Solution
{
public:
    vector<TreeNode *> delNodes(TreeNode *root, vector<int> &to_delete)
    {
        vector<TreeNode *> ans;
        unordered_set<int> s(to_delete.begin(), to_delete.end());
        stack<TreeNode *> st;
        st.push(root);
        if (!s.contains(root->val))
            ans.push_back(root);
        while (!st.empty())
        {
            if (st.top() == NULL)
            {
                st.pop();
                continue;
            }
            TreeNode *temp = st.top();
            st.pop();
            st.push(temp->right);
            st.push(temp->left);
            if (temp->right && s.contains(temp->right->val))
                temp->right = NULL;
            if (temp->left && s.contains(temp->left->val))
                temp->left = NULL;
            if (s.contains(temp->val))
            {
                if (temp->right && !s.contains(temp->right->val))
                    ans.push_back(temp->right);
                if (temp->left && !s.contains(temp->left->val))
                    ans.push_back(temp->left);
            }
        }
        return ans;
    }
};