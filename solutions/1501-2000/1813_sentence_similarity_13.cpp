/* https://leetcode.com/problems/sentence-similarity-iii/
1813. Sentence Similarity III
Medium
*/
class Solution
{
public:
    bool areSentencesSimilar(string sentence1, string sentence2)
    {
        bool s1_longer = sentence1.length() > sentence2.length();
        if (!s1_longer)
            swap(sentence1, sentence2);
        int n = sentence1.length();
        int m = sentence2.length();
        if (m == n)
            return sentence1 == sentence2;
        size_t find = sentence1.find(sentence2);
        bool bool1 = true, bool2 = true;
        if (find == 0)
        {
            if (sentence1[find + m] == ' ')
                return true;
            else
                bool1 = false;
        }
        if (sentence1.substr(n - m, m) == sentence2)
        {
            if (sentence1[n - m - 1] == ' ')
                return true;
            else
                bool2 = false;
        }
        if (!bool1 && !bool2)
            return false;
        if (find != string::npos)
            return false;
        int i = 0;
        while (sentence1[i] == sentence2[i])
            i++;
        if (i != 0)
            i--;
        if (sentence1[i] != ' ')
            return false;
        for (int j = 0; j < m - i; j++)
        {
            if (sentence1[n - j - 1] == sentence2[m - j - 1])
                continue;
            else
                return false;
        }
        if (sentence1[n - m + i] != ' ')
            return false;
        return true;
    }
};