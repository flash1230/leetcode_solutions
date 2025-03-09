/* https://leetcode.com/problems/alternating-groups-ii/
3208. Alternating Groups II
Medium
Sliding Window
*/
class Solution
{
public:
    int numberOfAlternatingGroups(vector<int> &colors, int k)
    {
        for (int i = 0; i < k - 1; i++)
            colors.push_back(colors[i]);
        int left = 0, right = 1, ans = 0;
        while (right < colors.size())
        {
            if (colors[right] == colors[right - 1])
                left = right;
            if (right - left == k - 1)
            {
                ans = 1;
                break;
            }
            right++;
        }
        if (!ans)
            return 0;
        right = left + k - 1;
        while (right + 1 < colors.size())
        {
            right++;
            if (colors[right] != colors[right - 1])
            {
                ans++;
                continue;
            }
            left = right;
            if (left + k - 1 >= colors.size())
                return ans;
            while (right + 1 < colors.size())
            {
                right++;
                if (colors[right] == colors[right - 1])
                    left = right;
                if (right - left == k - 1)
                {
                    ans++;
                    break;
                }
            }
        }
        return ans;
    }
};