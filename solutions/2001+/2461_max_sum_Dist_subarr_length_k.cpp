/* https://leetcode.com/problems/maximum-sum-of-distinct-subarrays-with-length-k/
2461. Maximum Sum of Distinct Subarrays With Length K
Medium
Sliding Window Map
*/
class Solution
{
public:
    long long maximumSubarraySum(vector<int> &nums, int k)
    {
        unordered_map<int, int> freq;
        int dob_count = 0;
        int left = 0;
        int right = k - 1;
        long long sum = 0;
        for (int i = left; i <= right; i++)
        {
            freq[nums[i]]++;
            sum += nums[i];
            if (freq[nums[i]] > 1)
                dob_count++;
        }
        long long ans = dob_count ? 0 : sum;
        while (right + 1 < nums.size())
        {
            freq[nums[left]]--;
            if (freq[nums[left]])
                dob_count--;
            sum -= nums[left];
            left++;
            right++;
            freq[nums[right]]++;
            if (freq[nums[right]] > 1)
                dob_count++;
            sum += nums[right];
            if (dob_count == 0)
                ans = max(sum, ans);
        }
        return ans;
    }
};