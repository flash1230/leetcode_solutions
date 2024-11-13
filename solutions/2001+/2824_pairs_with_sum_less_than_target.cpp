/* https://leetcode.com/problems/count-pairs-whose-sum-is-less-than-target/
2824. Count Pairs Whose Sum is Less than Target
Easy
Sorting Two Pointers
*/
class Solution
{
public:
    int countPairs(vector<int> &nums, int target)
    {
        sort(nums.begin(), nums.end());
        int ans = 0;
        int left = 0, right = nums.size() - 1;
        while (left < right)
        {
            if (nums[left] + nums[right] < target)
            {
                ans += right - left;
                left++;
            }
            else
                right--;
        }
        return ans;
    }
};