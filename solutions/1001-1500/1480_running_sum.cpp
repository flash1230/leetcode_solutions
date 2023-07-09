/* https://leetcode.com/problems/running-sum-of-1d-array/
1480. Running Sum of 1d Array
Easy
Array
*/
class Solution
{
public:
    vector<int> runningSum(vector<int> &nums)
    {
        vector<int> ans = {nums[0]};
        for (int i = 1; i < nums.size(); i++)
            ans.push_back(ans[i - 1] + nums[i]);
        return ans;
    }
};