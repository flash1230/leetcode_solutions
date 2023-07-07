/* https://leetcode.com/problems/container-with-most-water/
11. Container With Most Water
Medium
Two Pointers
*/
class Solution
{
public:
    int maxArea(vector<int> &height)
    {
        int i = 0;
        int j = height.size() - 1;
        int vol = 0;
        int max_vol = 0;
        while (j > i)
        {
            vol = min(height[i], height[j]) * (j - i);
            max_vol = max(vol, max_vol);
            if (height[i] < height[j])
                i++;
            else
                j--;
        }
        return max_vol;
    }
};