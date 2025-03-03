/* https://leetcode.com/problems/partition-array-according-to-given-pivot/
2161. Partition Array According to Given Pivot
Medium
Two Pointers
*/
class Solution
{
public:
    vector<int> pivotArray(vector<int> &nums, int pivot)
    {
        int n = nums.size();
        vector<int> ans(n, pivot);
        int left = 0, right = n - 1;
        for (int i = 0; i < n; i++)
        {
            if (nums[i] < pivot)
                ans[left++] = nums[i];
            if (nums[n - i - 1] > pivot)
                ans[right--] = nums[n - i - 1];
        }
        return ans;
    }
};