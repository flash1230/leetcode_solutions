/* https://leetcode.com/problems/count-the-number-of-fair-pairs/
2563. Count the Number of Fair Pairs
Medium
Sorting Two POinters
*/
class Solution
{
public:
    long long countFairPairs(vector<int> &nums, int lower, int upper)
    {
        sort(nums.begin(), nums.end());
        long long ans = 0;
        for (int i = 0, j = nums.size() - 1; i < j; i++)
        {
            while (i < j && nums[i] + nums[j] > upper)
                j--;
            ans += j - i;
        }
        for (int i = 0, j = nums.size() - 1; i < j; i++)
        {
            while (i < j && nums[i] + nums[j] > lower - 1)
                j--;
            ans -= j - i;
        }
        return ans;
    }
};