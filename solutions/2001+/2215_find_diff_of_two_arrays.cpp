/* https://leetcode.com/problems/find-the-difference-of-two-arrays/
2215. Find the Difference of Two Arrays
Easy
Set
*/
class Solution
{
public:
    vector<vector<int>> findDifference(vector<int> &nums1, vector<int> &nums2)
    {
        unordered_set<int> s1(nums1.begin(), nums1.end());
        unordered_set<int> s2(nums2.begin(), nums2.end());
        vector<vector<int>> ans;
        nums1.clear();
        nums2.clear();
        for (auto i : s1)
        {
            if (!s2.count(i))
                nums1.push_back(i);
        }
        for (auto i : s2)
        {
            if (!s1.count(i))
                nums2.push_back(i);
        }
        ans.push_back(nums1);
        ans.push_back(nums2);
        return ans;
    }
};