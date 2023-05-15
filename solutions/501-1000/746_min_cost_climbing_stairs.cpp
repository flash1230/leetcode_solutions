/* https://leetcode.com/problems/min-cost-climbing-stairs/
746. Min Cost Climbing Stairs
Easy
*/
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int len = cost.size();
        int ans[len];
        ans[0] = cost[0];
        ans[1] = cost[1];
        for(int i =2;i<len;i++) {
            ans[i] = cost[i] + min(ans[i-1], ans[i-2]);
        }
        return min(ans[len-1],ans[len-2]);
    }
};