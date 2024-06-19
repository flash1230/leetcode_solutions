/* https://leetcode.com/problems/minimum-number-of-days-to-make-m-bouquets
1482. Minimum Number of Days to Make m Bouquets
Medium
Binary Search
*/
class Solution
{
public:
    int bouquetCount(vector<int> &bloomDay, int adj, int day)
    {
        int res = 0;
        int cur_len = 0;
        for (int i = 0; i < bloomDay.size(); i++)
        {
            if (bloomDay[i] <= day)
            {
                cur_len++;
                if (cur_len == adj)
                {
                    res++;
                    cur_len = 0;
                }
            }
            else
                cur_len = 0;
        }
        return res;
    }

    int minDays(vector<int> &bloomDay, int m, int k)
    {
        int n = bloomDay.size();
        if (long(m) * long(k) > n)
            return -1;
        int cur = 0;
        for (int i : bloomDay)
            cur = max(cur, i);
        if (m * k == n)
            return cur;
        int left = 1, right = cur, mid;
        while (right > left)
        {
            mid = left + (right - left) / 2;
            if (bouquetCount(bloomDay, k, mid) < m)
                left = mid + 1;
            else
                right = mid;
        }
        return right;
    }
};