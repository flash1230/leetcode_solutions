/* https://leetcode.com/problems/minimum-index-of-a-valid-split/
2780. Minimum Index of a Valid Split
Medium
*/
class Solution
{
public:
    int minimumIndex(vector<int> &nums)
    {
        int n = nums.size();
        int mn = nums[0], tc = 0;
        for (int i : nums)
        {
            if (i == mn)
                tc++;
            else
                tc--;
            if (!tc)
            {
                mn = i;
                tc = 1;
            }
        }
        int count = 0;
        for (int i : nums)
        {
            if (i == mn)
                count++;
        }
        int other = 0;
        for (int i = 0; i < n; i++)
        {
            if (nums[i] != mn)
                other++;
            if (i + 1 > 2 * other && ((2 * count) - i - 1) > (n - (2 * other)))
                return i;
        }
        return -1;
    }
};