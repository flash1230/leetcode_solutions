/* https://leetcode.com/problems/minimum-number-of-k-consecutive-bit-flips
995. Minimum Number of K Consecutive Bit Flips
Hard
Sliding Window Bit Manipulation
*/
class Solution
{
public:
    int minKBitFlips(vector<int> &nums, int k)
    {
        int left = 0, right = left + k;
        int flips = 0;
        for (; left < nums.size();)
        {
            if (!nums[left])
            {
                flips++;
                for (int i = left; i < right; i++)
                {
                    if (i >= nums.size())
                        return -1;
                    nums[i] = !nums[i];
                }
            }
            left++;
            right = left + k;
        }
        return flips;
    }
};