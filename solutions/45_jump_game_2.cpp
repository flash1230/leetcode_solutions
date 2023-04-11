/* https://leetcode.com/problems/jump-game-ii/
45. Jump Game II
Medium
DP
*/
class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        int current = 0;
        int moves = 0;
        int cur_max = 0;
        if(n==1) {
            return 0;
        }
        for(int i = 0; i<n-1;i++) {
            cur_max = max(cur_max, i+nums[i]);
            if(i==current) {
                moves++;
                current = cur_max;
            }
        }
	    return moves;
    }
};