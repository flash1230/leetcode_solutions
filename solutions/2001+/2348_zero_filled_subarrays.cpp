/* https://leetcode.com/problems/number-of-zero-filled-subarrays/
2348. Number of Zero-Filled Subarrays
Medium
*/
class Solution
{
public:
    long long zeroFilledSubarray(vector<int> &nums)
    {
        long ans = 0;
        long cur_length = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == 0)
                cur_length++;
            else
            {
                if (cur_length)
                    ans += (cur_length * (cur_length + 1)) / 2;
                cur_length = 0;
            }
        }
        if (cur_length)
            ans += (cur_length * (cur_length + 1)) / 2;
        return ans;
    }
};