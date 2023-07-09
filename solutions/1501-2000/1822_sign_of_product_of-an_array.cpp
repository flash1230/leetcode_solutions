/* https://leetcode.com/problems/sign-of-the-product-of-an-array/
1822. Sign of the Product of an Array
Easy
*/
class Solution
{
public:
    int arraySign(vector<int> &nums)
    {
        bool neg = false;
        for (int i : nums)
        {
            if (i < 0)
                neg = !neg;
            if (i == 0)
                return 0;
        }
        return neg ? -1 : 1;
    }
};