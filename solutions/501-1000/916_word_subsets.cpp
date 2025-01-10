/* https://leetcode.com/problems/word-subsets/
916. Word Subsets
Medium
Map
*/
class Solution
{
public:
    vector<string> wordSubsets(vector<string> &words1, vector<string> &words2)
    {
        unordered_map<char, int> freq_main;
        unordered_map<char, int> freq;
        for (string s : words2)
        {
            for (char c : s)
                freq[c]++;
            for (auto i : freq)
                freq_main[i.first] = max(i.second, freq_main[i.first]);
            freq.clear();
        }
        vector<string> ans;
        unordered_map<char, int> temp;
        for (string s : words1)
        {
            temp = freq_main;
            for (char c : s)
            {
                if (temp.contains(c))
                {
                    temp[c]--;
                    if (temp[c] == 0)
                        temp.erase(c);
                }
            }
            if (temp.size() == 0)
                ans.push_back(s);
        }
        return ans;
    }
};