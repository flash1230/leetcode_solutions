/* https://leetcode.com/problems/valid-parentheses/
20. Valid Parentheses
Easy
*/
class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(auto x:s) {
            if(x=='(' || x=='{' || x == '[') {
                st.push(x);
            }
            else if(x == ')') {
                if(st.empty()|| st.top()!='(') {
                    return false;
                }
                st.pop();
            }
            else if(x == ']') {
                if(st.empty()|| st.top()!='[') {
                    return false;
                }
                st.pop();
            }
            else if(x == '}') {
                if(st.empty()|| st.top()!='{') {
                    return false;
                }
                st.pop();
            }
        }
        return st.empty();
    }
};