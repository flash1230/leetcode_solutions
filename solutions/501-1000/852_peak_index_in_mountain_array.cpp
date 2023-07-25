/* https://leetcode.com/problems/peak-index-in-a-mountain-array/
852. Peak Index in a Mountain Array
Medium
Binary Search
*/
class Solution
{
public:
    int check(vector<int> &arr, int a)
    {
        if (arr[a - 1] < arr[a] && arr[a] > arr[a + 1])
            return 0;
        else if (arr[a + 1] > arr[a])
            return 1;
        return 2;
    }

    int peakIndexInMountainArray(vector<int> &arr)
    {
        int l = 0;
        int r = arr.size() - 1;
        while (l != r)
        {
            int m = (l + r) / 2;
            int a = check(arr, m);
            if (a == 0)
                return (l + r) / 2;
            else if (a == 1)
                l = m + 1;
            else
                r = m;
        }
        return -1;
    }
};