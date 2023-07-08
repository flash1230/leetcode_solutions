/* https://leetcode.com/problems/intersection-of-two-arrays-ii/
350. Intersection of Two Arrays II
Easy
Map
*/
class Solution
{
public:
    vector<int> intersect(vector<int> &nums1, vector<int> &nums2)
    {
        vector<int> res;
        int n = nums1.size();
        int m = nums2.size();
        unordered_map<int, int> c1, c2;
        for (int i = 0; i < n; i++)
            c1[nums1[i]]++;
        for (int i = 0; i < m; i++)
            c2[nums2[i]]++;
        auto iter = c1.begin();
        while (iter != c1.end())
        {
            if (c2.find(iter->first) != c2.end())
            {
                int t = min(iter->second, c2[iter->first]);
                while (t != 0)
                {
                    res.push_back(iter->first);
                    t--;
                }
            }
            ++iter;
        }
        return res;
    }
};