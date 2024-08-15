/* https://leetcode.com/problems/find-k-th-smallest-pair-distance/
719. Find K-th Smallest Pair Distance
Hard
Binary Search Sliding Window
*/
class Solution
{
public:
    int counter(vector<int> &nums, int target)
    {
        int count = 0, left = 0;
        for (int right = 1; right < nums.size(); ++right)
        {
            while (nums[right] - nums[left] > target)
                ++left;
            count += right - left;
        }
        return count;
    }
    int smallestDistancePair(vector<int> &nums, int k)
    {
        sort(nums.begin(), nums.end());
        int left = 0, right = nums[nums.size() - 1] - nums[0];
        while (left < right)
        {
            int m = left + (right - left) / 2;
            if (counter(nums, m) < k)
                left = m + 1;
            else
                right = m;
        }
        return left;
    }
};