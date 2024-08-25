/* https://leetcode.com/problems/number-complement/
476. Number Complement
Easy
Bitwise
*/
class Solution
{
public:
    int findComplement(int num)
    {
        long pow_two = 2;
        int temp = num;
        while (temp >> 1)
        {
            temp >>= 1;
            pow_two <<= 1;
        }
        return pow_two - num - 1;
    }
};