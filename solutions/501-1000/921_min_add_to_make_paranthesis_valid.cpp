/* https://leetcode.com/problems/minimum-add-to-make-parentheses-valid
921. Minimum Add to Make Parentheses Valid
Medium
Stack
*/
class Solution
{
public:
    int minAddToMakeValid(string s)
    {
        stack<char> st;
        int t = s.length();
        int i = 0;
        while (i < t)
        {
            if (s[i] == ')' && !st.empty() && st.top() == '(')
                st.pop();
            else
                st.push(s[i]);
            i++;
        }
        return st.size();
    }
};