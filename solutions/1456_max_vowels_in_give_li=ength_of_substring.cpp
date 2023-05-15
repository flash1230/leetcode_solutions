/* https://leetcode.com/problems/maximum-number-of-vowels-in-a-substring-of-given-length/
1456. Maximum Number of Vowels in a Substring of Given Length
Medium
Sliding Window
*/
class Solution {
public:
    int maxVowels(string s, int k) {
        int count = 0;
        int j;
        for(j = 0;j<k;j++) {
            if(isVowel(s[j])){
                count++;
            }
        }
        if(count == k){
            return k;
        }
        int ans = count;
        for(int i = 0,j=k-1;j<s.length()-1;i++,j++){
            if(isVowel(s[i]))
                count--;
            if(isVowel(s[j+1]))
                count++;
            if(count == k)
                return k;
            ans=max(ans, count);
        }
        return ans;
    }
    bool isVowel(char c){
        if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u'){
            return true;
        }
        return false;
    }
};