/* https://leetcode.com/problems/delete-and-earn/
740. Delete and Earn
Medium
DP Array
*/
class Solution
{
public:
    int deleteAndEarn(vector<int> &nums)
    {
        if (nums.size() == 1)
            return nums[0];
        map<int, int> freq_map;
        int n = 0;
        for (int x = 0; x < nums.size(); x++)
        {
            freq_map[nums[x]]++;
            n = max(n, nums[x]);
        }
        for (int i = 0; i <= n; i++)
            freq_map[i] = i * freq_map[i] + max(freq_map[i - 2], freq_map[i - 3]);
        return max(freq_map[n], freq_map[n - 1]);
    }
};