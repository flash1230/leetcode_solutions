/* https://leetcode.com/problems/build-array-from-permutation/
1920 Build Array from Permutation
Easy
Array
*/
class Solution {
public:
    vector<int> buildArray(vector<int>& nums) {
        vector<int> ans;
        for(int i=0;i<nums.size();i++) {
            ans.push_back(nums[nums[i]]);
        }
        return ans;
    }
};