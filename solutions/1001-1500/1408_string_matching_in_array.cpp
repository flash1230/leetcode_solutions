/*https://leetcode.com/problems/string-matching-in-an-array/
1408. String Matching in an Array
Easy
*/
class Solution
{
public:
    vector<string> stringMatching(vector<string> &words)
    {
        vector<string> ans;
        for (int i = 0; i < words.size(); i++)
        {
            for (int j = 0; j < words.size(); j++)
            {
                if (j == i || words[i].length() > words[j].length())
                    continue;
                if (words[j].find(words[i]) != string::npos)
                {
                    ans.push_back(words[i]);
                    break;
                }
            }
        }
        return ans;
    }
};