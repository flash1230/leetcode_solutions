/* https://leetcode.com/problems/water-bottles/
1518. Water Bottles
Easy
Math
*/
class Solution
{
public:
    int numWaterBottles(int numBottles, int numExchange)
    {
        int ans = numBottles;
        int spareBottles = numBottles;
        while (spareBottles >= numExchange)
        {
            ans += spareBottles / numExchange;
            spareBottles = spareBottles % numExchange + spareBottles / numExchange;
        }
        return ans;
    }
};