/* https://leetcode.com/problems/check-if-array-is-sorted-and-rotated/
1752. Check if Array Is Sorted and Rotated
Easy
*/
class Solution
{
public:
    bool check(vector<int> &nums)
    {
        int n = nums.size();
        if (n <= 2)
            return true;
        bool moved = false;
        for (int i = 1; i < n; i++)
        {
            if (nums[i] >= nums[i - 1])
            {
                if (!moved)
                    continue;
                else
                {
                    if (nums[i] > nums[0])
                        return false;
                }
            }
            else
            {
                if (moved)
                    return false;
                moved = true;
                if (nums[i] > nums[0])
                    return false;
            }
        }
        return true;
    }
};