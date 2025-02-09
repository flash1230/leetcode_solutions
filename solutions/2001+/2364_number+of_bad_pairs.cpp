/* https://leetcode.com/problems/count-number-of-bad-pairs/
2364. Count Number of Bad Pairs
Medium
Map
*/
class Solution
{
public:
    long long countBadPairs(vector<int> &nums)
    {
        unordered_map<int, int> diff;
        long long count = 0;
        long long ans = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            diff[i - nums[i]]++;
            count++;
            ans += count - diff[i - nums[i]];
        }
        return ans;
    }
};