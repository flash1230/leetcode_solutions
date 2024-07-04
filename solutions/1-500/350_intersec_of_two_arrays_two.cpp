/* https://leetcode.com/problems/intersection-of-two-arrays-ii/
350. Intersection of Two Arrays II
Easy
Map
*/
class Solution1
{
public:
    vector<int> intersect(vector<int> &nums1, vector<int> &nums2)
    {
        vector<int> res;
        int n = nums1.size();
        unordered_map<int, int> c1;
        for (int i = 0; i < n; i++)
            c1[nums1[i]]++;
        for (int i : nums2)
        {
            if (c1[i] && c1[i] >= 1)
            {
                res.push_back(i);
                c1[i]--;
            }
        }
        return res;
    }
};

class Solution2
{
public:
    vector<int> intersect(vector<int> &nums1, vector<int> &nums2)
    {
        vector<int> res;
        int a = nums1.size();
        int b = nums2.size();
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        int i = 0, j = 0;
        while (1)
        {
            if (i == a || j == b)
                break;
            if (nums1[i] == nums2[j])
            {
                res.push_back(nums1[i]);
                i++;
                j++;
            }
            else if (nums1[i] < nums2[j])
                i++;
            else
                j++;
        }
        return res;
    }
};