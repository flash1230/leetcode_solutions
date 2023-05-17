/* https://leetcode.com/problems/count-ways-to-build-good-strings/
2466. Count Ways To Build Good Strings
Medium
DP
*/
class Solution {
public:
    int countGoodStrings(int low, int high, int zero, int one) {
        int modulo = 1e9 + 7;
        vector<int> dp(high+1, 0);
        dp[0] = 1;
        for(int i = 1; i<=high;i++) {
          if(zero<=i){
            dp[i]=(dp[i-zero]+ dp[i])%modulo;
          }
          if(one<=i){
            dp[i]=(dp[i-one] + dp[i])%modulo;
          }
        }
        int ans= 0;
        for(int i = low;i<=high;i++){
          ans=(dp[i] +ans)%modulo;
        }
        return ans;
    }
};