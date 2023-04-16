/* https://leetcode.com/problems/candy/
135. Candy
Hard
Greedy
*/
class Solution
{
public:
    int candy(vector<int> &ratings)
    {
        int n = ratings.size();
        int ans = n;
        if (n == 1)
        {
            return 1;
        }
        vector<int> v(n, 1);
        for (int i = 1; i < n; i++)
        {
            if (ratings[i] > ratings[i - 1])
            {
                v[i] = v[i - 1] + 1;
                ans += v[i - 1];
            }
        }
        for (int i = n - 2; i >= 0; i--)
        {
            if (ratings[i] > ratings[i + 1])
            {
                if (v[i] <= v[i + 1])
                {
                    ans += v[i + 1] + 1 - v[i];
                    v[i] = v[i + 1] + 1;
                }
            }
        }
        return ans;
    }
};