/* https://leetcode.com/problems/merge-sorted-array/
88. Merge Sorted Array
Easy
*/
class Solution
{
public:
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
    {
        if (m == 0)
        {
            while (n--)
            {
                nums1[n] = nums2[n];
            }
            return;
        }
        int i = m - 1, j = n - 1;
        int max = m + n;
        while (max--)
        {
            if (i == -1)
            {
                while (j != -1)
                {
                    nums1[max] = nums2[j];
                    max--;
                    j--;
                }
                return;
            }
            if (j == -1)
            {
                return;
            }
            if (nums1[i] >= nums2[j])
            {
                nums1[max] = nums1[i];
                i--;
            }
            else
            {
                nums1[max] = nums2[j];
                j--;
            }
        }
    }
};