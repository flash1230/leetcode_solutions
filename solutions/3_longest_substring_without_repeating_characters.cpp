/* https://leetcode.com/problems/longest-substring-without-repeating-characters/
3. Longest Substring Without Repeating Characters
Medium
Two Pointers Map
*/
class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        int l = s.length();
        if (l < 2)
        {
            return l;
        }
        int start = 0;
        int end = 1;
        int ans = 1;
        unordered_map<char, int> pos;
        pos[s[0]] = 0;
        while (end < l)
        {
            if (pos.count(s[end]) && pos[s[end]] >= start)
            {
                ans = max(ans, end - start);
                start = pos[s[end]] + 1;
            }
            pos[s[end]] = end;
            end++;
        }
        return max(ans, end - start);
    }
};
