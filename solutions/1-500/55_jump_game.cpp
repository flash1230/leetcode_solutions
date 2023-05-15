/* https://leetcode.com/problems/jump-game/
55. Jump Game
Medium
DP
*/
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int canReach = n-1;
        if(n==1) {
            return true;
        }
        for(int i = n-2; i>=0;i--) {
            if(i+nums[i]>=canReach) {
                canReach = i;
            }
        }
        return canReach==0;
    }
};