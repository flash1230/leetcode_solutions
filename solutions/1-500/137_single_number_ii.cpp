/* https://leetcode.com/problems/single-number-ii/
137. Single Number II
Medium
*/
class Solution1
{
public:
    int singleNumber(vector<int> &nums)
    {
        unordered_map<int, int> mp;
        for (int i : nums)
            mp[i]++;
        for (auto i : mp)
        {
            if (i.second != 3)
                return i.first;
        }
        return -3;
    }
};

class Solution2
{
public:
    int singleNumber(vector<int> &nums)
    {
        int n = nums.size();
        if (n == 1)
            return nums[0];
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n - 3; i = i + 3)
        {
            if (nums[i] != nums[i + 1])
                return nums[i];
        }
        return nums[n - 1];
    }
};