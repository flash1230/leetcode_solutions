/* https://leetcode.com/problems/uncommon-words-from-two-sentences/
884. Uncommon Words from Two Sentences
Easy
*/
class Solution
{
public:
    vector<string> uncommonFromSentences(string s1, string s2)
    {
        unordered_map<string, int> hehe;
        string s;
        for (int i = 0; i < s1.length(); i++)
        {
            while (i < s1.length() && s1[i] != ' ')
                s += s1[i++];
            hehe[s]++;
            s = "";
        }
        for (int i = 0; i < s2.length(); i++)
        {
            while (i < s2.length() && s2[i] != ' ')
                s += s2[i++];
            hehe[s]++;
            s = "";
        }
        vector<string> ans;
        for (auto i : hehe)
        {
            if (i.second == 1)
                ans.push_back(i.first);
        }
        return ans;
    }
};