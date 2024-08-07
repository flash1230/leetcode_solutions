/* https://leetcode.com/problems/range-sum-of-sorted-subarray-sums/
1508. Range Sum of Sorted Subarray Sums
Medium
Sorting Binary Search
*/
class Solution
{
public:
    int rangeSum(vector<int> &nums, int n, int left, int right)
    {
        vector<int> sums{};
        for (int i = 0; i < n; i++)
        {
            int prefixSum = 0;
            for (int j = i; j < n; j++)
            {
                prefixSum += nums[j];
                sums.push_back(prefixSum);
            }
        }
        sort(begin(sums), end(sums));
        int res = accumulate(sums.begin() + left - 1, sums.begin() + right, 0LL) % 1000000007;
        return res;
    }
};