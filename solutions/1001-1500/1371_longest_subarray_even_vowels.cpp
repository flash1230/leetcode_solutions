/* https://leetcode.com/problems/find-the-longest-substring-containing-vowels-in-even-counts/
1371. Find the Longest Substring Containing Vowels in Even Counts
Medium
Prefix Sum Map
*/
class Solution {
public:
    int findTheLongestSubstring(string s) {
        vector<int> vowels(5, 0);
        int ans = 0;
        unordered_map<string, int> mp;
        for(int i = 0; i< s.length(); i++)
        {
            if(s[i]=='a')
                vowels[0]++;
            if(s[i]=='e')
                vowels[1]++;
            if(s[i]=='i')
                vowels[2]++;
            if(s[i]=='o')
                vowels[3]++;
            if(s[i]=='u')
                vowels[4]++;
            string even = to_string(vowels[0]%2) + to_string(vowels[1]%2) + to_string(vowels[2]%2) + to_string(vowels[3]%2) + to_string(vowels[4]%2);
            if(even == "00000")
                ans = i+1;
            else
            {
                if(!mp.contains(even))
                    mp[even] = i;
                ans = max(ans, i - mp[even]);
            }
        }
        return ans;
    }
};