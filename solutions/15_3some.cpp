/* https://leetcode.com/problems/3sum/
15. 3Sum(hmmmm)
Medium
*/
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int selected = 0;
        vector<vector<int>> fans;
        while(selected<nums.size() && nums[selected]<1) {
            if(selected>0 && nums[selected]==nums[selected-1]) {
                selected++;
                continue;
            }
            int l = selected+1;
            int r = nums.size()-1;
            while(l<r) {
                if(nums[l]+nums[r] < -nums[selected]) {
                    l++;
                }
                else if(nums[l]+nums[r] > -nums[selected]) {
                    r--;
                }
                else {
                    vector<int> ans;
                    ans.push_back(nums[l]);
                    ans.push_back(nums[r]);
                    ans.push_back(nums[selected]);
                    fans.push_back(ans);
                while (l+1<nums.size() && nums[l]==nums[l+1]){
                    l++;
                } 
                while (r-1>1 && nums[r]==nums[r-1]) {
                    r--;
                }
                l++;
                r--;
                }
            }
            selected++;
        }
        return fans;
    }
};