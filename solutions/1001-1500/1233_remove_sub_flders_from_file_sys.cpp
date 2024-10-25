/* https://leetcode.com/problems/remove-sub-folders-from-the-filesystem/
1233. Remove Sub-Folders from the Filesystem
Medium
Sorting
*/
class Solution
{
public:
    bool check(string s1, string s2)
    {
        if (s1.length() > s2.length())
            return false;
        int i = 0;
        for (; i < s1.length(); i++)
        {
            if (s1[i] != s2[i])
                return false;
        }
        if (i == s2.length() || s2[i] == '/')
            return true;
        return false;
    }
    vector<string> removeSubfolders(vector<string> &folder)
    {
        vector<string> ans;
        sort(folder.begin(), folder.end());
        ans.push_back(folder[0]);
        for (int i = 1; i < folder.size(); i++)
        {
            if (!check(ans.back(), folder[i]))
                ans.push_back(folder[i]);
        }
        return ans;
    }
};