/* https://leetcode.com/problems/is-subsequence/
392. Is Subsequence
Easy
*/
class Solution {
public:
    bool isSubsequence(string s, string t) {
        if(s.length()==0) {
            return true;
        }
        int a = 0;
        for(int i = 0;i<t.length();i++) {
            if(s[a] == t[i]) {
                a++;
            }
            if(a==s.length()) {
                return true;
            }
        }
        return false;
    }
};