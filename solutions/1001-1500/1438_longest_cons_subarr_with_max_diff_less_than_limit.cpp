/* https://leetcode.com/problems/longest-continuous-subarray-with-absolute-diff-less-than-or-equal-to-limit
1438. Longest Continuous Subarray With Absolute Diff Less Than or Equal to Limit
Medium
Sliding Window Deque*/
class Solution
{
public:
    int longestSubarray(vector<int> &nums, int limit)
    {
        deque<int> maq, miq;
        int left = 0, right;
        int ans = 0;
        for (right = 0; right < nums.size(); right++)
        {
            while (!miq.empty() && miq.back() > nums[right])
                miq.pop_back();
            miq.push_back(nums[right]);
            while (!maq.empty() && maq.back() < nums[right])
                maq.pop_back();
            maq.push_back(nums[right]);
            while (maq.front() - miq.front() > limit)
            {
                if (maq.front() == nums[left])
                    maq.pop_front();
                if (miq.front() == nums[left])
                    miq.pop_front();
                left++;
            }
            ans = max(ans, right - left + 1);
        }
        return ans;
    }
};