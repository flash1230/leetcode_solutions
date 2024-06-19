/* https://leetcode.com/problems/koko-eating-bananas
875. Koko Eating Bananas
Medium
Binary Search
*/
class Solution
{
public:
    bool isPossible(vector<int> &piles, int h, int k)
    {
        int t = 0;
        for (int i : piles)
        {
            t += ceil((double)i / (double)k);
            if (t > h)
                return false;
        }
        return t <= h;
    }

    int minEatingSpeed(vector<int> &piles, int h)
    {
        int l = 1;
        int r;
        int s = 0;
        for (int i : piles)
            s = max(s, i);
        r = ceil(s / (ceil(h / piles.size())));
        while (l < r)
        {
            int m = (l + r) / 2;
            if (isPossible(piles, h, m))
                r = m;
            else
                l = m + 1;
        }
        return l;
    }
};