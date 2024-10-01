/* https://leetcode.com/problems/check-if-array-pairs-are-divisible-by-k/
1497. Check If Array Pairs Are Divisible by k
Medium
Map
*/
class Solution
{
public:
    bool canArrange(vector<int> &arr, int k)
    {
        int n = k / 2 + 1;
        vector<int> remainder(n, 0);
        for (auto i : arr)
        {
            int rem = (i % k);
            if (rem < 0)
                rem += k;
            if (rem < n)
                remainder[rem]++;
            else
                remainder[k - rem]--;
        }
        if (k % 2 == 0)
        {
            if (remainder[k / 2] % 2 == 0)
                remainder[k / 2] = 0;
            else
                return false;
        }
        if (remainder[0] % 2 == 0)
            remainder[0] = 0;
        else
            return false;
        for (int i : remainder)
        {
            if (i != 0)
                return false;
        }
        return true;
    }
};