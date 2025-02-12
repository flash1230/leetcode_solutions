/* https://leetcode.com/problems/max-sum-of-a-pair-with-equal-sum-of-digits/
2342. Max Sum of a Pair With Equal Sum of Digits
Medium
Map
*/
class Solution
{
public:
    int sumOfDigits(int num)
    {
        if (num < 10)
            return num;
        else
            return num % 10 + sumOfDigits(num / 10);
    }
    int maximumSum(vector<int> &nums)
    {
        unordered_map<int, vector<int>> pairs;
        for (int i : nums)
        {
            int a = sumOfDigits(i);
            if (!pairs.contains(a))
            {
                pairs[a] = {i};
            }
            else if (pairs[a].size() < 2)
                pairs[a].push_back(i);
            else
            {
                if (pairs[a][0] > i)
                {
                    if (pairs[a][1] < i)
                        pairs[a][1] = i;
                }
                else if (pairs[a][1] > i)
                {
                    if (pairs[a][0] < i)
                        pairs[a][0] = i;
                }
                else
                {
                    if (pairs[a][0] > pairs[a][1])
                        pairs[a][1] = i;
                    else
                        pairs[a][0] = i;
                }
            }
        }
        int ans = -1;
        for (auto i : pairs)
        {
            if (i.second.size() < 2)
                continue;
            else
                ans = max(ans, i.second[0] + i.second[1]);
        }
        return ans;
    }
};