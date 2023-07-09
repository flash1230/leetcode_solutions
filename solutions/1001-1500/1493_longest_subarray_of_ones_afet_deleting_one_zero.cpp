/* https://leetcode.com/problems/longest-subarray-of-1s-after-deleting-one-element/
1493. Longest Subarray of 1's After Deleting One Element
Medium
*/
class Solution
{
public:
    int longestSubarray(vector<int> &nums)
    {
        int n = nums.size();
        bool zero = false;
        int start = 0;
        int end = 0;
        int mid = 0;
        int cur = 0;
        int ans = 0;
        while (nums[start] == 0)
            start++;
        for (end = start + 1; end < n; end++)
        {
            if (!nums[end])
            {
                if (zero)
                {
                    cur = end - start - 1;
                    ans = max(cur, ans);
                    start = mid + 1;
                    mid = end;
                }
                else
                {
                    cur = end - start;
                    zero = true;
                    mid = end;
                }
            }
        }
        if (nums[n - 1])
        {
            cur = n - start - 1;
            if (mid < start)
                cur = n - start;
        }
        if (!zero && start == 0)
            return n - 1;
        return max(cur, ans);
    }
};