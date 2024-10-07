/* https://leetcode.com/problems/minimum-string-length-after-removing-substrings/
2696. Minimum String Length After Removing Substrings
Easy
Stack
*/
class Solution
{
public:
    int minLength(string s)
    {
        stack<char> w;
        int i = 0;
        while (i < s.length())
        {
            if (w.empty())
                w.push(s[i]);
            else
            {
                if (s[i] == 'B' && w.top() == 'A')
                    w.pop();
                else if (s[i] == 'D' && w.top() == 'C')
                    w.pop();
                else
                    w.push(s[i]);
            }
            i++;
        }
        return w.size();
    }
};