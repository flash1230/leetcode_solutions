/* https://leetcode.com/problems/can-place-flowers/
605. Can Place Flowers
Easy
*/
class Solution
{
public:
    bool canPlaceFlowers(vector<int> &flowerbed, int n)
    {
        int l = flowerbed.size();
        if (n == 0)
        {
            return true;
        }
        if (l == 1)
        {
            if (n == 1 && flowerbed[0] == 0)
            {
                return true;
            }
            return false;
        }
        if (flowerbed[0] == 0 && flowerbed[1] == 0)
        {
            n--;
            flowerbed[0] = 1;
            if (n == 0)
            {
                return true;
            }
        }
        for (int i = 1; i < l - 1; i++)
        {
            if (flowerbed[i] == 0 && flowerbed[i - 1] == 0 && flowerbed[i + 1] == 0)
            {
                flowerbed[i] = 1;
                n--;
                if (n == 0)
                {
                    return true;
                }
            }
        }
        if (flowerbed[l - 1] == 0 && flowerbed[l - 2] == 0)
        {
            flowerbed[l - 1] = 1;
            n--;
        }
        return n == 0 ? true : false;
    }
};