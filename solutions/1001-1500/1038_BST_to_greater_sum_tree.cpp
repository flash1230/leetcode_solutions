class Solution
{
public:
    TreeNode *bstToGst(TreeNode *root)
    {
        int cur_sum = 0;
        stack<TreeNode *> st;
        st.push(root);
        while (!st.empty())
        {
            if (st.top()->right)
            {
                st.push(st.top()->right);
                continue;
            }
            else
            {
                while (1)
                {
                    st.top()->val += cur_sum;
                    cur_sum = st.top()->val;
                    TreeNode *t;
                    t = st.top()->left;
                    st.pop();
                    if (t)
                        st.push(t);
                    if (st.empty())
                        break;
                    if (st.top()->left != NULL)
                    {
                        st.top()->val += cur_sum;
                        cur_sum = st.top()->val;
                        TreeNode *t = st.top()->left;
                        st.pop();
                        st.push(t);
                        break;
                    }
                }
            }
        }
        return root;
    }
};