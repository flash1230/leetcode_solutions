/* https://leetcode.com/problems/add-digits/
258. Add Digits
Easy
Math
*/
class Solution
{
public:
    int addDigits(int num)
    {
        return (num - 1) % 9 + 1;
    }
};