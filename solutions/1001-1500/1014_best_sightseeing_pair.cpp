/* https://leetcode.com/problems/best-sightseeing-pair/
1014. Best Sightseeing Pair
Medium
Two Pointers
*/
class Solution
{
public:
    int maxScoreSightseeingPair(vector<int> &values)
    {
        int one = 0;
        int two = 0;
        for (int i = 0; i < values.size(); i++)
        {
            one = max(one, two + values[i] - i);
            two = max(two, values[i] + i);
        }
        return one;
    }
};