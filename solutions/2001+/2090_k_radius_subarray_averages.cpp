/* https://leetcode.com/problems/k-radius-subarray-averages/
2090. K Radius Subarray Averages
Medium
Sliding Window
*/
class Solution
{
public:
    vector<int> getAverages(vector<int> &nums, int k)
    {
        vector<int> ans;
        int n = nums.size();
        int win = 2 * k + 1;
        if (n < win)
        {
            vector<int> res(n, -1);
            return res;
        }
        for (int i = 0; i < k && i < n; i++)
            ans.push_back(-1);
        long sum = 0;
        for (int i = 0; i < win; i++)
            sum += nums[i];
        for (int i = win; i <= n; i++)
        {
            ans.push_back(sum / win);
            if (i == n)
                break;
            sum = sum - nums[i - win] + nums[i];
        }
        for (int i = 0; i < k; i++)
            ans.push_back(-1);
        return ans;
    }
};