/* https://leetcode.com/problems/house-robber-ii/
213. House Robber II
Medium
DP
*/
class Solution {
public:
    int rob_trad(vector<int>& nums) {
        int n = nums.size();
        int dp[n];
        if(n==1) {
            return nums[0];
        }
        if(n==2)
            return max(nums[1], nums[0]);
        dp[0] = nums[0];
        dp[1] = nums[1];
        dp[2] = nums[0]+nums[2];
            if(n>=3){
        for (int i =3;i<nums.size();i++) {
            dp[i] = nums[i] + max(dp[i-2],dp[i-3]);
        }
            }
        return max(dp[n-1], dp[n-2]);
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==1)
            return nums[0];
        if(n==2)
            return max(nums[1], nums[0]);
        if(n>=3) {
            vector<int> nA(nums.begin() + 1, nums.end()); 
            vector<int> B(nums.begin(), nums.end()-1);
        int a = rob_trad(nA);
        int b = rob_trad(B);
        return max(a,b);
        }
        return 1;
    }
};