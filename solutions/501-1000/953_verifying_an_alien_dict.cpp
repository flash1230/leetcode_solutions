/* https://leetcode.com/problems/verifying-an-alien-dictionary/
953. Verifying an Alien Dictionary
Easy
Map
*/
class Solution
{
public:
    bool isAlienSorted(vector<string> &words, string order)
    {
        unordered_map<char, int> ord;
        for (int i = 0; i < 26; i++)
            ord[order[i]] = i;
        for (int i = 1; i < words.size(); i++)
        {
            int j = 0;
            while (j < words[i - 1].length() || j < words[i].length())
            {
                if (ord[words[i - 1][j]] > ord[words[i][j]])
                    return false;
                else if (ord[words[i - 1][j]] < ord[words[i][j]])
                    break;
                else
                {
                    j++;
                    if (j == words[i - 1].length() && words[i - 1].length() > words[i].length())
                        return false;
                }
            }
        }
        return true;
    }
};