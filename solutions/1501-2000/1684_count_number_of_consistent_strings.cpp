/* https://leetcode.com/problems/count-the-number-of-consistent-strings/
1684. Count the Number of Consistent Strings
Easy
*/
class Solution
{
public:
    int countConsistentStrings(string allowed, vector<string> &words)
    {
        unordered_set<char> br;
        br.insert(allowed.begin(), allowed.end());
        int ans = words.size();
        for (auto word : words)
        {
            for (int i = 0; i < word.size(); i++)
            {
                if (!br.contains(word[i]))
                {
                    ans--;
                    break;
                }
            }
        }
        return ans;
    }
};