/* https://leetcode.com/problems/permutation-in-string/
567. Permutation in String
Medium
Sliding Window
*/
class Solution
{
public:
    bool checkInclusion(string s1, string s2)
    {
        unordered_map<char, int> orig;
        for (auto s : s1)
            orig[s]++;
        unordered_map<char, int> checker;
        int i = 0, j = s1.length() - 1;
        while (j < s2.length())
        {
            if (!orig[s2[i]])
            {
                i++;
                j = i + s1.length() - 1;
                checker.clear();
            }
            else
            {
                if (checker[s2[i]] + 1 > orig[s2[i]])
                {
                    int start = j - s1.length() + 1;
                    while (1)
                    {
                        checker[s2[start]]--;
                        if (s2[start] != s2[i])
                        {
                            j++;
                            start++;
                        }
                        else
                            break;
                    }
                    checker[s2[i]]++;
                    i++;
                    j++;
                }
                else
                {
                    checker[s2[i]]++;
                    i++;
                    if (i > j)
                        return true;
                }
            }
        }
        return false;
    }
};