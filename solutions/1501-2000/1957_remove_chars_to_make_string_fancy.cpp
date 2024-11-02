/* https://leetcode.com/problems/delete-characters-to-make-fancy-string/
1957. Delete Characters to Make Fancy String
Easy
*/
class Solution {
public:
    string makeFancyString(string s) {
        if(s.length()<3)
            return s;
        for(int i = 2; i<s.length(); i++)
        {
            if(s[i]==s[i-1] && s[i]==s[i-2])
            {
                int k = 1;
                while((k+i)<s.length() && s[k+i]==s[i])
                    k++;
                s.erase(i,k);
            }
        }
        return s;
    }
};