/* https://leetcode.com/problems/minimum-recolors-to-get-k-consecutive-black-blocks/
2379. Minimum Recolors to Get K Consecutive Black Blocks
Easy
Sliding Window
*/
class Solution
{
public:
    int minimumRecolors(string blocks, int k)
    {
        int cur = 0, ans = INT_MAX;
        for (int i = 0; i < k; i++)
        {
            if (blocks[i] == 'W')
                cur++;
        }
        ans = min(ans, cur);
        for (int i = k; i < blocks.size(); i++)
        {
            if (blocks[i - k] == 'W')
                cur--;
            if (blocks[i] == 'W')
                cur++;
            ans = min(cur, ans);
        }
        return ans;
    }
};