/* https://leetcode.com/problems/minimum-number-of-removals-to-make-mountain-array/
1671. Minimum Number of Removals to Make Mountain Array
Hard
Binary Search DP
*/
class Solution
{
public:
    int minimumMountainRemovals(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> sub(n, 1);
        vector<int> lis = {nums[0]};
        for (int i = 1; i < nums.size(); i++)
        {
            int index = lower_bound(lis.begin(), lis.end(), nums[i]) - lis.begin();
            if (index == lis.size())
                lis.push_back(nums[i]);
            else
                lis[index] = nums[i];
            sub[i] = lis.size();
        }
        reverse(nums.begin(), nums.end());
        lis.clear();
        lis.push_back(nums[0]);
        vector<int> sab(n, 1);
        for (int i = 1; i < nums.size(); i++)
        {
            int index = lower_bound(lis.begin(), lis.end(), nums[i]) - lis.begin();
            if (index == lis.size())
                lis.push_back(nums[i]);
            else
                lis[index] = nums[i];
            sab[i] = lis.size();
        }
        reverse(sab.begin(), sab.end());
        int ans = INT_MAX;
        for (int i = 0; i < n; i++)
        {
            if (sub[i] > 1 and sab[i] > 1)
                ans = min(ans, n - sub[i] - sab[i] + 1);
        }
        return ans;
    }
};