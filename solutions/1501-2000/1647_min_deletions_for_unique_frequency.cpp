/* https://leetcode.com/problems/minimum-deletions-to-make-character-frequencies-unique/
1647. Minimum Deletions to Make Character Frequencies Unique
Medium
Map
*/
class Solution
{
public:
    int minDeletions(string s)
    {
        int n = s.length();
        if (n < 2)
            return 0;
        int ans = 0;
        unordered_map<char, int> freq;
        for (int i = 0; i < n; i++)
            freq[s[i]]++;
        vector<bool> sd(n);
        for (auto i : freq)
        {
            int temp = i.second;
            if (sd[temp])
            {
                while (sd[temp])
                {
                    ans++;
                    temp--;
                    if (temp == 0)
                    {
                        sd[0] = false;
                        continue;
                    }
                }
                sd[temp] = true;
            }
            else
                sd[temp] = true;
        }
        return ans;
    }
};