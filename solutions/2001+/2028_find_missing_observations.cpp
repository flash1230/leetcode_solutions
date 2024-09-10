/* https://leetcode.com/problems/find-missing-observations/
2028. Find Missing Observations
Medium
*/
class Solution
{
public:
    vector<int> combo(int count, int remaining)
    {
        vector<int> ans;
        if (remaining > count * 6 || remaining < count)
            return ans;
        while (count != 1)
        {
            ans.push_back(remaining / count);
            remaining -= remaining / count;
            count--;
        }
        ans.push_back(remaining);
        return ans;
    }
    vector<int> missingRolls(vector<int> &rolls, int mean, int n)
    {
        int sum = 0;
        for (int i : rolls)
            sum += i;
        return combo(n, mean * (n + rolls.size()) - sum);
    }
};