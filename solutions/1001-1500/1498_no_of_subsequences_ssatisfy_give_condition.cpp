/* https://leetcode.com/problems/number-of-subsequences-that-satisfy-the-given-sum-condition/
1498. Number of Subsequences That Satisfy the Given Sum Condition
Medium
Two Pointers Sorting
*/
class Solution
{
public:
    int numSubseq(vector<int> &nums, int target)
    {
        int res = 0, mod = pow(10, 9) + 7;
        sort(nums.begin(), nums.end());
        int left = 0, right = nums.size() - 1;
        vector<int> pows(right + 1);
        pows[0] = 1;
        for (int i = 1; i <= right; i++)
            pows[i] = pows[i - 1] * 2 % mod;
        while (left <= right)
        {
            if (nums[left] + nums[right] > target)
                right--;
            else
            {
                res = (res + pows[right - left]) % mod;
                left++;
            }
        }
        return res;
    }
};