/* https://leetcode.com/problems/longest-subarray-with-maximum-bitwise-and
2419. Longest Subarray With Maximum Bitwise AND
Medium
Bit Manipulation
*/
class Solution
{
public:
    int longestSubarray(vector<int> &nums)
    {
        int cur_length = 1, max_length = 1, max_val = nums[0];
        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i] > max_val)
            {
                max_val = nums[i];
                max_length = 1;
                cur_length = 1;
            }
            else if (nums[i] == max_val)
            {
                if (nums[i - 1] == nums[i])
                    cur_length++;
                else
                    cur_length = 1;
            }
            else
            {
                max_length = max(cur_length, max_length);
                cur_length = 0;
            }
        }
        return max(max_length, cur_length);
    }
};