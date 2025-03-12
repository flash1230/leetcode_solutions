/* https://leetcode.com/problems/maximum-count-of-positive-integer-and-negative-integer/
2529. Maximum Count of Positive Integer and Negative Integer
Easy
Binary Search
*/
class Solution
{
public:
    int binarySearch(vector<int> &nums, int left, int right, bool positive)
    {
        int m;
        if (positive)
        {
            if (nums[right] <= 0)
                return -1;
            while (1)
            {
                m = (left + right) / 2;
                if (nums[m] <= 0)
                    left = m + 1;
                else
                    right = m;
                if (left == right)
                    return left;
                if (left + 1 == right)
                {
                    if (nums[left] > 0)
                        return left;
                    else
                        return right;
                }
                if (left > right)
                    return -1;
            }
        }
        if (nums[left] >= 0)
            return -1;
        while (1)
        {
            m = (left + right) / 2;
            if (nums[m] >= 0)
                right = m - 1;
            else
                left = m;
            if (left == right)
                return left;
            if (left + 1 == right)
            {
                if (nums[right] < 0)
                    return right;
                else
                    return left;
            }
            if (left > right)
                return -1;
        }
        return m;
    }
    int maximumCount(vector<int> &nums)
    {
        int r = nums.size() - 1;
        if (nums[0] > 0)
            return r + 1;
        if (nums[r] < 0)
            return r + 1;
        int firstpos = binarySearch(nums, 0, r, true);
        if (firstpos == -1)
            firstpos = r + 1;
        if (firstpos < (r / 2))
            return r - firstpos + 1;
        int lastneg = binarySearch(nums, 0, firstpos - 1, false);
        return max(r - firstpos + 1, lastneg + 1);
    }
};