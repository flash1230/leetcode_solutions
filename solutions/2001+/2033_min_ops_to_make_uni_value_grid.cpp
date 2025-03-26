/* https://leetcode.com/problems/minimum-operations-to-make-a-uni-value-grid/
2033. Minimum Operations to Make a Uni-Value Grid
Medium
Sorting
*/
class Solution
{
public:
    int minOperations(vector<vector<int>> &grid, int x)
    {
        vector<int> nums;
        int a = grid[0][0];
        for (int i = 0; i < grid.size(); i++)
        {
            for (int j : grid[i])
            {
                if ((j - a) % x != 0)
                    return -1;
                else
                    nums.push_back(j);
            }
        }
        int n = nums.size();
        sort(nums.begin(), nums.end());
        for (int i = 1; i < n; i++)
            nums[i] = (nums[i] - nums[0]) / x;
        nums[0] = 0;
        int median;
        if (n % 2)
            median = nums[n / 2];
        else
        {
            int s = nums[n / 2] + nums[(n / 2) - 1];
            if (s % 2)
                median = nums[n / 2];
            else
                median = s / 2;
        }
        int ans = 0;
        for (int i : nums)
            ans += abs(i - median);
        return ans;
    }
};