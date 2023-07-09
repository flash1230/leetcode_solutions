/* https://leetcode.com/problems/valid-anagram/
242. Valid Anagram
Easy
Map
*/
class Solution
{
public:
    bool isAnagram(string s, string t)
    {
        if (s.length() != t.length())
            return false;
        unordered_map<char, int> mm;
        for (int i = 0; i < t.length(); i++)
        {
            mm[s[i]]++;
            mm[t[i]]--;
        }
        for (auto x : mm)
        {
            if (x.second != 0)
                return false;
        }
        return true;
    }
};