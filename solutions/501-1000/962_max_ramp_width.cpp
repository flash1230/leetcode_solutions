/* https://leetcode.com/problems/maximum-width-ramp/
962. Maximum Width Ramp
Medium
Two Pointers
*/
class Solution
{
public:
    int maxWidthRamp(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> mr(n);
        int t = INT_MIN;
        for (int i = n - 1; i >= 0; i--)
        {
            t = max(t, nums[i]);
            mr[i] = t;
        }
        int ans = 0, left = 0, right = 1;
        while (left <= right && right < n)
        {
            if (mr[right] >= nums[left])
            {
                ans = max(ans, right - left);
                right++;
            }
            else
                left++;
        }
        return ans;
    }
};