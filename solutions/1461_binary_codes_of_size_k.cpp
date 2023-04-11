/* https://leetcode.com/problems/check-if-a-string-contains-all-binary-codes-of-size-k/
1461. Check If a String Contains All Binary Codes of Size K
Medium
Sets
*/
class Solution
{
public:
    bool hasAllCodes(string s, int k)
    {
        if (k > s.size())
            return false;
        unordered_set<string> my_set;
        for (int i = 0; i <= s.size() - k; i++)
            my_set.insert(s.substr(i, k));

        return my_set.size() == pow(2, k);
    }
};