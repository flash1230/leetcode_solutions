/* https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/
167. Two Sum II - Input Array Is Sorted
Medium
Two Pointers
*/
class Solution
{
public:
    vector<int> twoSum(vector<int> &numbers, int target)
    {
        int l = 0;
        int r = numbers.size() - 1;
        vector<int> ans;
        while (l < r)
        {
            if (numbers[l] + numbers[r] == target)
            {
                ans.push_back(l + 1);
                ans.push_back(r + 1);
                return ans;
            }
            if (numbers[l] + numbers[r] < target)
            {
                l++;
                continue;
            }
            if (numbers[l] + numbers[r] > target)
            {
                r--;
                continue;
            }
        }
        return ans;
    }
};