/* https://leetcode.com/problems/reverse-substrings-between-each-pair-of-parentheses
1190. Reverse Substrings Between Each Pair of Parentheses
Medium
Stack
*/
class Solution
{
public:
    string reverseParentheses(string s)
    {
        string ans = "";
        stack<string> st;
        for (char c : s)
        {
            if (c == '(')
            {
                st.push(ans);
                ans = "";
            }
            else if (c == ')')
            {
                reverse(ans.begin(), ans.end());
                ans = st.top() + ans;
                st.pop();
            }
            else
                ans += c;
        }
        return ans;
    }
};