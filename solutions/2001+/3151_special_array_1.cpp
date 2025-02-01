/* https://leetcode.com/problems/special-array-i/
3151. Special Array I
Easy
*/
class Solution
{
public:
    bool isArraySpecial(vector<int> &nums)
    {
        int n = nums.size();
        if (n < 2)
            return true;
        for (int i = 1; i < n; i++)
        {
            if ((nums[i] + nums[i - 1]) % 2)
                continue;
            else
                return false;
        }
        return true;
    }
};