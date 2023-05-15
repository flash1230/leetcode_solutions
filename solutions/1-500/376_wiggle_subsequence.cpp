/* https://leetcode.com/problems/wiggle-subsequence/
376. Wiggle Subsequence
Medium
*/
class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int n = nums.size();
        if(n<2) {
            return 1;
        }
        int i = 1;
        while(nums[i] == nums[i-1]) {
            i++;
            if(i==n) {
                return 1;
            }
        }
        int l = 2;
        bool isInc = nums[i]>nums[i-1];
        int low = isInc ? nums[i-1] : nums[i];
        int high = !isInc ? nums[i-1] : nums[i];
        for(;i<n;i++) {
            if(isInc) {
                if(nums[i]>high) {
                    high = nums[i];
                }
                else if(nums[i]<high) {
                    isInc = false;
                    low = nums[i];
                    l++;
                }
            }
            else {
                if(nums[i]>low) {
                    isInc = true;
                    high = nums[i];
                    l++;
                }
                else {
                    low = nums[i];
                }
            }
        }
        return l;
    }
};