/* https://leetcode.com/problems/apply-operations-to-an-array/description/
2460. Apply Operations to an Array
Easy
*/
class Solution
{
public:
    vector<int> applyOperations(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> ans;
        for (int i = 0; i < n; i++)
        {
            if (nums[i] == 0)
                continue;
            if (i == n - 1)
            {
                if (nums[i])
                    ans.push_back(nums[i]);
                break;
            }
            if (nums[i] == nums[i + 1])
            {
                ans.push_back(2 * nums[i]);
                i++;
            }
            else
                ans.push_back(nums[i]);
        }
        while (ans.size() != nums.size())
            ans.push_back(0);
        return ans;
    }
};