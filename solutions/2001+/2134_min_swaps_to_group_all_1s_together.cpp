/* https://leetcode.com/problems/minimum-swaps-to-group-all-1s-together-ii/
2134. Minimum Swaps to Group All 1's Together II
Medium
Sliding Window
*/
class Solution
{
public:
    int zero = 0;
    int one = 0;
    int swipe(bool val, vector<int> &nums)
    {
        int count = val ? one : zero;
        int winCount = 0;
        for (int i = 0; i < count; i++)
        {
            if (nums[i] == val)
                winCount++;
        }
        int ans = winCount;
        for (int i = count; i < nums.size(); i++)
        {
            if (nums[i] == val)
                winCount++;
            if (nums[i - count] == val)
                winCount--;
            ans = max(ans, winCount);
        }
        return count - ans;
    }
    void count(vector<int> &nums)
    {
        for (int i : nums)
            i == 1 ? one++ : zero++;
    }
    int minSwaps(vector<int> &nums)
    {
        count(nums);
        if (min(zero, one) < 2)
            return 0;
        return min(swipe(0, nums), swipe(1, nums));
    }
};