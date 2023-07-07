/* https://leetcode.com/problems/plus-one/
66. Plus One
Easy
Math
*/
class Solution
{
public:
    vector<int> plusOne(vector<int> &digits)
    {
        int n = digits.size() - 1;
        if (digits[n] != 9)
        {
            digits[n]++;
            return digits;
        }
        while (1)
        {
            digits[n] = 0;
            if (n != 0 && digits[n - 1] != 9)
            {
                digits[n - 1]++;
                return digits;
            }
            n--;
            if (n == -1)
            {
                vector<int> ans;
                ans.push_back(1);
                ans.insert(ans.end(), digits.begin(), digits.end());
                return ans;
            }
        }
        return digits;
    }
};