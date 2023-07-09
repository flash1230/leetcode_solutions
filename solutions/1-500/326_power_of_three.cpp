/* https://leetcode.com/problems/power-of-three/
326. Power of Three
Easy
Math
*/
class Solution
{
public:
    bool isPowerOfThree(int n)
    {
        return fmod(log(n) / log(3), 1) == 0;
    }
};