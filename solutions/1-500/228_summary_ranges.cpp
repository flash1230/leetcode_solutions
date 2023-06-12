/* https://leetcode.com/problems/summary-ranges
228. Summary Ranges
Easy
*/
class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        int n = nums.size();
        vector<string> ans;
        if(n==0){
            return ans;
        }
        int cur = nums[0];
        for(int i = 1; i<n; i++) {
            if(nums[i]!=nums[i-1]+1){
                if(nums[i-1]==cur){
                    ans.push_back(to_string(cur));
                }
                else {
                    ans.push_back(to_string(cur)+"->"+to_string(nums[i-1]));
                }
                cur = nums[i];
            }
        }
        if(nums[n-1]==cur){
            ans.push_back(to_string(cur));
            }
        else {
            ans.push_back(to_string(cur)+"->"+to_string(nums[n-1]));
        }
        return ans;
    }
};