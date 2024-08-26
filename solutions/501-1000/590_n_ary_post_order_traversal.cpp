/* https://leetcode.com/problems/n-ary-tree-postorder-traversal/
590. N-ary Tree Postorder Traversal
Easy
Tree
*/
class Solution
{
public:
    vector<int> postorder(Node *root)
    {
        vector<int> ans;
        if (root == NULL)
            return ans;
        stack<Node *> st;
        st.push(root);
        while (!st.empty())
        {
            Node *temp = st.top();
            st.pop();
            for (auto i : temp->children)
                st.push(i);
            ans.push_back(temp->val);
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};