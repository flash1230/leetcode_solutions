/* https://leetcode.com/problems/longest-arithmetic-subsequence-of-given-difference/
1218. Longest Arithmetic Subsequence of Given Difference
Medium
Map DP
*/
class Solution
{
public:
    int longestSubsequence(vector<int> &arr, int difference)
    {
        unordered_map<int, int> mp;
        mp[arr[0]] = 1;
        int ans = 1;
        for (int i = 1; i < arr.size(); i++)
        {
            int t = arr[i] - difference;
            if (mp.count(t))
            {
                mp[arr[i]] = mp[t] + 1;
                ans = max(ans, mp[arr[i]]);
            }
            else
            {
                mp[arr[i]] = 1;
            }
        }
        return ans;
    }
};