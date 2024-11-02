/* https://leetcode.com/problems/longest-square-streak-in-an-array/
2501. Longest Square Streak in an Array
Medium
*/
class Solution
{
public:
    int longestSquareStreak(vector<int> &nums)
    {
        unordered_set<int> numbers;
        for (int i : nums)
            numbers.insert(i);
        int ans = -1;
        for (int i : nums)
        {
            int current = 1;
            for (int j = 2;; j = j * 2)
            {
                if (pow(i, j) > 1e5)
                    break;
                if (numbers.contains(pow(i, j)))
                    current++;
                else
                    break;
            }
            ans = max(ans, current);
        }
        return ans > 1 ? ans : -1;
    }
};