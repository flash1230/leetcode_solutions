/* https://leetcode.com/problems/maximum-candies-allocated-to-k-children
2226. Maximum Candies Allocated to K Children
Medium
Binary Search
*/
class Solution
{
public:
    bool possible(vector<int> &candies, int num, int k)
    {
        int count = 0;
        for (int i = candies.size() - 1; i >= 0; i--)
        {
            if (candies[i] < num)
                break;
            count += candies[i] / num;
            if (count >= k)
                return true;
        }
        return count >= k;
    }
    int maximumCandies(vector<int> &candies, long long k)
    {
        long long total = 0;
        for (int i : candies)
            total += i;
        if (total < k)
            return 0;
        sort(candies.begin(), candies.end());
        int left = 1, right = total / k + 1;
        while (left < right)
        {
            int m = (left + right) / 2;
            if (possible(candies, m, k))
                left = m;
            else
                right = m;
            if (left == right || right - left == 1)
                return left;
        }
        return left;
    }
};