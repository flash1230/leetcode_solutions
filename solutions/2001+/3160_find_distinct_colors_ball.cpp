/* https://leetcode.com/problems/find-the-number-of-distinct-colors-among-the-balls/
3160. Find the Number of Distinct Colors Among the Balls
Medium
Map
*/
class Solution
{
public:
    vector<int> queryResults(int limit, vector<vector<int>> &queries)
    {
        unordered_map<int, int> colour_count, ball;
        int count = 0;
        vector<int> ans;
        for (auto i : queries)
        {
            if (ball[i[0]] > 0)
            {
                colour_count[ball[i[0]]]--;
                if (colour_count[ball[i[0]]] == 0)
                    count--;
            }
            ball[i[0]] = i[1];
            if (!colour_count[i[1]])
                count++;
            colour_count[i[1]]++;
            ans.push_back(count);
        }
        return ans;
    }
};