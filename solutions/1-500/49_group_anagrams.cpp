/* https://leetcode.com/problems/group-anagrams/
49. Group Anagrams
Medium
*/
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;
        for( string s: strs ) {
            string t = s;
            sort(t.begin(), t.end());
            mp[t].push_back(s);
        }
        vector<vector<string>> anagrams;
        for(auto g: mp) {
            anagrams.push_back(g.second);
        }
        return anagrams;
    }
};