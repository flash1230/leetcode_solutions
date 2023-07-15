/* https://leetcode.com/problems/search-insert-position/
35. Search Insert Position
Easy
Binary Search
*/
class Solution
{
public:
    int searchInsert(vector<int> &v, int target)
    {
        return lower_bound(v.begin(), v.end(), target) - v.begin();
    }
};