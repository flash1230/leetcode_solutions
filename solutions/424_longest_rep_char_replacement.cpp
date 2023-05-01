/* https://leetcode.com/problems/longest-repeating-character-replacement/
424. Longest Repeating Character Replacement
Medium
Sliding Window
*/
class Solution
{
public:
    int characterReplacement(string s, int k)
    {
        int l = s.length();
        if (l < 2)
        {
            return 1;
        }
        int i = 0, j = 0;
        int cur = 0, ans = 0;
        unordered_map<char, int> hash;
        while (j < l)
        {
            hash[s[j]]++;
            cur = max(cur, hash[s[j]]);
            if ((j - i + 1) - cur > k)
            {
                hash[s[i]]--;
                i++;
            }
            ans = max(ans, j - i + 1);
            j++;
        }
        return ans;
    }
};