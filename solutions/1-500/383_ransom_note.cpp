/* https://leetcode.com/problems/ransom-note/
383. Ransom Note
Easy
*/
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int> count;
        for(auto i: magazine) {
            count[i]++;
        }
        for(auto i: ransomNote) {
            if(count[i] == 0) 
                return false;
            count[i]--;
        }
        return true;
    }
};