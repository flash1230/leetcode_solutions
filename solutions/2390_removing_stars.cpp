/* https://leetcode.com/problems/removing-stars-from-a-string/
2390. Removing Stars From a String
Medium
*/
class Solution {
public:
    string removeStars(string s) {
        stack<char> st;
        int l = 0;
        while(l<s.length()) {
            if(s[l]=='*') {
                st.pop();
            }
            else {
                st.push(s[l]);
            }
            l++;
        }
        string res = "";
        while(!st.empty()) {
            res+=st.top();
            st.pop();
        }
        reverse(res.begin(), res.end()); 
        return res;
    }
};