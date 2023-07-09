/* https://leetcode.com/problems/kids-with-the-greatest-number-of-candies/
1431. Kids With the Greatest Number of Candies
Easy
*/
class Solution
{
public:
    vector<bool> kidsWithCandies(vector<int> &candies, int extraCandies)
    {
        int max_candies = candies[0];
        for (int i = 1; i < candies.size(); i++)
            max_candies = max(max_candies, candies[i]);
        vector<bool> result;
        for (int i = 0; i < candies.size(); i++)
        {
            if (candies[i] + extraCandies >= max_candies)
                result.push_back(true);
            else
                result.push_back(false);
        }
        return result;
    }
};