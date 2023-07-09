/* https://leetcode.com/problems/merge-strings-alternately/
1768. Merge Strings Alternately
Easy
*/
class Solution
{
public:
    string mergeAlternately(string word1, string word2)
    {
        string res;
        res += word1[0];
        res += word2[0];
        int i = 1, j = 1;
        while (1)
        {
            if (word1[i] != '\0')
                res.push_back(word1[i++]);
            if (word2[j] != '\0')
                res.push_back(word2[j++]);
            if (word1[i] == '\0' && word2[j] == '\0')
                return res;
        }
        return res;
    }
};