/* https://leetcode.com/problems/find-the-longest-valid-obstacle-course-at-each-position
1964. Find the Longest Valid Obstacle Course at Each Position
Hard
Binary Search
*/
class Solution
{
public:
    vector<int> longestObstacleCourseAtEachPosition(vector<int> &obstacles)
    {
        vector<int> ans(obstacles.size(), 1);
        vector<int> till;
        for (int i = 0; i < obstacles.size(); i++)
        {
            int index = upper_bound(till.begin(), till.end(), obstacles[i]) - till.begin();
            if (index == till.size())
                till.push_back(obstacles[i]);
            else
                till[index] = obstacles[i];
            ans[i] = index + 1;
        }
        return ans;
    }
};