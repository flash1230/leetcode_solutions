/* https://leetcode.com/problems/valid-palindrome/
125. Valid Palindrome
Easy
*/
class Solution
{
public:
    bool isPalindrome(string s)
    {
        int start = 0;
        int end = s.length() - 1;
        while (start < end)
        {
            if (!isalnum(s[start]))
            {
                start++;
                continue;
            }
            if (!isalnum(s[end]))
            {
                end--;
                continue;
            }
            if (s[start] == s[end])
            {
                start++;
                end--;
                continue;
            }
            if (isalpha(s[start]) && isalpha(s[end]) && (abs(s[start] - s[end]) == 32))
            {
                start++;
                end--;
                continue;
            }
            return false;
        }
        return true;
    }
};