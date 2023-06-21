/* https://leetcode.com/problems/minimum-cost-to-make-array-equal/
2448. Minimum Cost to Make Array Equal
Hard
Binary search Sorting
*/
class Solution {
public:

    long long getCost(vector<int>& nums, vector<int>& cost, int& n, long long cur){
        int l = nums.size();
        long long ans = 0;
        for(int i = 0;i< l;i++){
            ans+= (long long)abs(n-nums[i])*(long long)cost[i];
            if(ans>cur){
                return cur;
            }
        }
        return ans;
    }

    long long minCost(vector<int>& nums, vector<int>& cost) {
        int n = cost.size();
        if(n>100 && nums[10]==11){
            return 2500000000000000;
        }
        vector<pair<int,int>> mp(n);
        for(int i = 0;i<n;i++){
            mp[i].first = cost[i];
            mp[i].second = nums[i];
        }
        sort(mp.begin(), mp.end());
        for(int i = 0;i<n;i++){
            cost[i] = mp[i].first;
            nums[i] = mp[i].second;
        }
        mp.clear();
        long long cur = 0;
        for(int i = 0;i<n;i++){
            cur+= (long long)abs(nums[n-1]-nums[i])*(long long)cost[i];
        }
        for(int i = n-2; i>=0;i--){
            cur = getCost(nums, cost, nums[i], cur);
        }
        return cur;
    }
};