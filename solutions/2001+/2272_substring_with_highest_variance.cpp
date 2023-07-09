/* https://leetcode.com/problems/substring-with-largest-variance/
2272. Substring With Largest Variance
Hard
DP
*/
class Solution
{
public:
    int largestVariance(string s)
    {
        int ans = 0;
        vector<int> freq(26, 0);
        for (int i = 0; i < s.length(); i++)
            freq[s[i] - 'a']++;
        for (int ii = 0; ii < 26; ii++)
        {
            for (int j = 0; j < 26; j++)
            {
                if (ii == j || freq[ii] == 0 || freq[j] == 0)
                    continue;
                else
                {
                    int maj = 0;
                    int minor = 0;
                    int rm = freq[j];
                    for (int i = 0; i < s.size(); i++)
                    {
                        if (s[i] == ii + 'a')
                            maj++;
                        else if (s[i] == j + 'a')
                        {
                            minor++;
                            rm--;
                        }
                        if (minor > 0)
                            ans = max(maj - minor, ans);
                        if (maj < minor && rm > 0)
                        {
                            maj = 0;
                            minor = 0;
                        }
                    }
                }
            }
        }
        return ans;
    }
};